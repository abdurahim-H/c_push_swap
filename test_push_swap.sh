#!/bin/bash

executable="./push_swap"  # Your executable
tests_per_size=1  # Number of tests per size increment

# Function to generate a random array with both positive and negative numbers
generate_random_array() {
	local size=$1
	local array=()
	while ((${#array[@]} < size)); do
		# Generate numbers between -1000 and 1000
		local num=$((RANDOM % 2001 - 1000))
		# Check if the number is already in the array
		if ! [[ ${array[*]} =~ $num ]]; then
			array+=($num)
		fi
	done
	echo ${array[*]}
}

while true; do
	echo "Enter 1 for 10 elements, 2 for 50 elements, 3 for 100 elements, 4 for 500 elements, or any other key to exit:"
	read choice
	case $choice in
		1) size=10 ;;
		2) size=50 ;;
		3) size=100 ;;
		4) size=500 ;;
		*) echo "Exiting..."; exit 0 ;;
	esac

	echo "Testing size: $size"
	for ((test = 1; test <= tests_per_size; test++)); do
		# Generate the array and store the output
		test_array=$(generate_random_array $size)
		echo "Test case $test: $test_array"
		gtime -f "Elapsed time: %E" $executable $test_array
	done
	echo "-------------------------------------"
done