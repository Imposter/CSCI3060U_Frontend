#!/bin/bash

# Expand patterns
shopt -s nullglob

# Clear screen
clear

# Run all tests
echo ==========================================================
echo Running frontend tests
cd tests

# Find all files that end with .inp in any child directory
for f in ./**/*.inp; do
    TEST_FILE="${f##*/}"
    TEST_NAME="${TEST_FILE%%.*}"
    TEST_PATH="${f%/*}/"

    echo ==========================================================
    echo Running test $TEST_NAME
    printf "\n"
    echo Test path: $TEST_PATH
    echo Test file: $TEST_FILE
    printf "\n"

    # Remove previous transaction test information to prevent appending and recreate the file
    rm $TEST_PATH/$TEST_NAME.atf >/dev/null 2>&1
    touch $TEST_PATH/$TEST_NAME.atf

    # Run program with redirected IO
    "../build/frontend" current_users.txt available_items.txt $TEST_PATH/$TEST_NAME.atf <$f >$TEST_PATH/$TEST_NAME.out 2>&1
    if [ ! $? -eq 0 ]; then
        # An error occurred while running the frontend, stop all tests and let the user know
        echo Frontend exitted unexpectedly, check $TEST_PATH/$TEST_NAME.out for more information...
        printf "\n"

        # Return to project root folder
        cd ..
        exit 1
    fi

    # Check if the test failed
    diff $TEST_PATH/$TEST_NAME.etf $TEST_PATH/$TEST_NAME.atf
    if [ ! $? -eq 0 ]; then
        # A test failed, stop all tests and let the user know
        echo Test $TEST_NAME failed

        # Return to project root folder
        cd ..
        exit 1
    else
        echo Test $TEST_NAME succeeded!
        printf "\n"
    fi
done

echo All tests completed successfully!

# Return to project root folder
cd ..