#!/bin/bash

# Function to generate random numbers
generate_numbers() {
    local count=$1
    local min=$2
    local max=$3
    local numbers=()
    
    for ((i=0; i<count; i++)); do
        number=$((RANDOM % (max - min + 1) + min))
        numbers+=($number)
    done
    
    echo "${numbers[@]}"
}

# Function to run push_swap and check the result
run_test() {
    local numbers=("$@")
    local expected_output=$(printf "%s\n" "${numbers[@]}" | sort -n | tr '\n' ' ')
    local push_swap_output=$(./push_swap "${numbers[@]}")
    local sorted_output=$(echo "$push_swap_output" | ./checker_MAC "${numbers[@]}")
    
    if [ "$sorted_output" = "OK" ]; then
        echo "Test Passed: ${numbers[@]}"
    else
        echo "Test Failed: ${numbers[@]}"
        echo "Push Swap Output: $push_swap_output"
    fi
}

# Test case 1: Empty input
run_test

# Test case 2: Single element input
run_test 42

# Test case 3: Small input sizes
run_test 2 1 3
run_test 5 2 4 1 3
run_test 7 6 5 4 3 2 1

# Test case 4: Large input sizes
run_test $(generate_numbers 100 1 100)
run_test $(generate_numbers 500 1 500)

# Test case 5: Reversed input
run_test 5 4 3 2 1
run_test 10 9 8 7 6 5 4 3 2 1

# Test case 6: Random permutations
for ((i=0; i<10; i++)); do
    run_test $(generate_numbers 50 1 100)
done