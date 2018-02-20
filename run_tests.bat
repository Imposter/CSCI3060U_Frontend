@echo off

:: Evaluate local variables on execution
setlocal EnableDelayedExpansion

:: Clear screen
cls

:: Run all tests
echo ==========================================================
echo Running frontend tests
cd tests
for /r %%f in (*.inp) do (
    set TEST_NAME=%%~nf
    set TEST_PATH=%%~dpf
    set TEST_FILE=%%~nxf

    echo ==========================================================
    echo Running test !TEST_NAME!
    echo:
    echo Test path: !TEST_PATH!
    echo Test file: !TEST_FILE!
    echo:

    :: Remove previous transaction test information to prevent appending and recreate the file
    del /q !TEST_PATH!\\!TEST_NAME!.atf >NUL
    copy /b NUL !TEST_PATH!\\!TEST_NAME!.atf >NUL

    :: Run program with redirected IO
    "..\\build\\frontend.exe" current_users.txt available_items.txt !TEST_PATH!\\!TEST_NAME!.atf <%%f >!TEST_PATH!\\!TEST_NAME!.out 2>&1
    if errorlevel 1 (
        :: An error occurred while running the frontend, stop all tests and let the user know
        echo Frontend exitted unexpectedly, check !TEST_PATH!\\!TEST_NAME!.out for more information...
        echo:
        goto end
    )

    :: Check if the test failed
    fc !TEST_PATH!\\!TEST_NAME!.etf !TEST_PATH!\\!TEST_NAME!.atf
    if errorlevel 1 (
        :: A test failed, stop all tests and let the user know
        echo Test !TEST_NAME! failed
        echo:
        goto end
    ) else (
        echo Test !TEST_NAME! succeeded!
        echo:
    )
)

echo All tests completed successfully!

:end
    :: Return to project root folder
    cd ..

    :: Restore local variable evaluation
    endlocal