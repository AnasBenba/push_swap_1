#!/bin/bash

# Test script for validating an array of integers

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

PROGRAM="./push_swap"  # Path to your program, modify if needed
TESTS_PASSED=0
TESTS_FAILED=0
VERBOSE=0  # Default: Not verbose
NUM_TESTS=100  # Default number of test cases
ARRAY_SIZE=500  # Default size of each test case

# Function to display help message
show_help() {
    echo "Usage: $0 [options]"
    echo
    echo "Options:"
    echo "  -v          Enable verbose mode (logs additional details in 'tests.log')."
    echo "  -h          Show this help message."
    echo "  -t [NUMBER] Specify the number of test cases to run (default: 100)."
    echo "  -s [NUMBER] Specify the size of each test case (default: 500 integers)."
    exit 0
}

# Function to run a single test case
run_test() {
    local INPUT=$1

    # Run the program and capture its output
    OUTPUT=$($PROGRAM $INPUT | wc -l)
    if [[ $VERBOSE -eq 1 ]]; then
        echo "Input: $INPUT" >> tests.log
        LOG=$($PROGRAM $INPUT | tr '\n' '\t')
        echo "Output: $LOG" >> tests.log
    fi

    # Validate the output
    if [[ $OUTPUT -lt 5500 ]]; then
        echo -e "PASSED ${GREEN}$OUTPUT${RESET}"
        [[ $VERBOSE -eq 1 ]] && echo -e "PASSED ${GREEN}$OUTPUT${RESET}" >> tests.log
        ((TESTS_PASSED++))
    elif [[ $OUTPUT -ge 5500 && $OUTPUT -lt 5800 ]]; then
        echo -e "WARNING ${YELLOW}$OUTPUT${RESET}"
        [[ $VERBOSE -eq 1 ]] && echo -e "WARNING ${YELLOW}$OUTPUT${RESET}" >> tests.log
        ((TESTS_FAILED++))
    else
        echo -e "FAILED ${RED}$OUTPUT${RESET}"
        [[ $VERBOSE -eq 1 ]] && echo -e "FAILED ${RED}$OUTPUT${RESET}" >> tests.log
        ((TESTS_FAILED++))
    fi
}

# Parse command-line arguments
while getopts ":vht:s:" opt; do
    case $opt in
        t)
            if ! [[ $OPTARG =~ ^[0-9]+$ ]]; then
                echo "Error: -t requires a numeric argument." >&2
                exit 1
            fi
            NUM_TESTS=$OPTARG
            ;;
        s)
            if ! [[ $OPTARG =~ ^[0-9]+$ ]]; then
                echo "Error: -s requires a numeric argument." >&2
                exit 1
            fi
            ARRAY_SIZE=$OPTARG
            ;;
        v)
            VERBOSE=1
            ;;
        h)
            show_help
            ;;
        *)
            echo "Invalid option: -$OPTARG" >&2
            show_help
            ;;
    esac
done

# Initialize verbose logging
[[ $VERBOSE -eq 1 ]] && echo "Verbose mode enabled. Logging to 'tests.log'." && > tests.log

# Test cases
echo "Running $NUM_TESTS tests with array size $ARRAY_SIZE..."

for ((i = 1; i <= NUM_TESTS; i++)); do
    INPUT=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-2147483648, 2147483647), $ARRAY_SIZE))))")
    run_test "$INPUT"
done

# Summary of results
echo
echo -e "Tests Passed: ${GREEN}$TESTS_PASSED${RESET}"
echo -e "Tests Failed: ${RED}$TESTS_FAILED${RESET}"

if [[ $TESTS_FAILED -eq 0 ]]; then
    echo -e "${GREEN}All tests passed successfully!${RESET}"
else
    echo -e "${RED}Some tests failed. Please review the output.${RESET}"
fi
