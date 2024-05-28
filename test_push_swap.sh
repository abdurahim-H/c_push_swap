#!/bin/bash

executable="./push_swap"  # Your executable
max_size=100  # Maximum number of elements
tests_per_size=5  # Number of tests per size increment

# Function to generate a random array with both positive and negative numbers
generate_random_array() {
	local size=$1
	local array=()
	for ((i = 0; i < size; i++)); do
		# Generate numbers between -1000 and 1000
		local num=$((RANDOM % 1001 - 500))
		array+=($num)
	done
	echo ${array[*]}
}

# Test across different sizes
for ((size = 10; size <= max_size; size += 10)); do
	echo "Testing size: $size"
	for ((test = 1; test <= tests_per_size; test++)); do
		# Generate the array and store the output
		test_array=$(generate_random_array $size)
		echo "Test case $test: $test_array"
		gtime -f "Elapsed time: %E" $executable $test_array
	done
	echo "-------------------------------------"
done