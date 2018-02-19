@echo off

REM Run all tests
echo Running frontend tests
cd tests
for /r %%f in (*.inp) do (
    REM Store test information
    set TEST_NAME=%%~nf
    set TEST_PATH=%%~dpf
    set TEST_FILE=%%~nxf

    echo Running test %TEST_NAME%
    echo Test path: %TEST_PATH%
    echo Test file: %TEST_FILE%

    REM Remove previous transaction test information to prevent appending and recreate the file
    del %TEST_PATH%\\%TEST_NAME%.atf
    copy /b NUL %TEST_PATH%\\%TEST_NAME%.atf >NUL

    REM Run program with redirected IO
    "..\\build\\frontend.exe" current_users.txt available_items.txt %TEST_PATH%\\%TEST_NAME%.atf <%%f >%TEST_PATH%\\%TEST_NAME%.out 2>&1
    if errorlevel 1 (
        REM An error occurred while running the frontend, stop all tests and let the user know
        echo Frontend exitted unexpectedly, check %TEST_PATH%\\%TEST_NAME%.out for more information...
        goto end
    )

    REM Check if the test failed
    fc %TEST_PATH%\\%TEST_NAME%.etf %TEST_PATH%\\%TEST_NAME%.atf
    if errorlevel 1 (
        REM A test failed, stop all tests and let the user know
        echo Test %TEST_NAME% failed
        goto end
    ) else (
        echo Test %TEST_NAME% succeeded!
    )
)

:end
    cd ..