/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:10:13 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/26 04:44:49 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	convert_to_long(char *str)
{
	char	*endptr;
	long	num;

	errno = 0;
	num = strtol(str, &endptr, 10);
	if (str == endptr || *endptr != '\0' || errno == ERANGE
		|| num > INT_MAX || num < INT_MIN)
	{
		fprintf(stderr, "Error\n");
		return (-1);
	}
	return (num);
}

int	process_args(int argc, char **argv, int *arr)
{
	long	num;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		num = convert_to_long(argv[i + 1]);
		if (num == -1)
			return (1);
		arr[i] = (int)num;
		i++;
	}
	return (0);
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int check_duplicates(int arr[], int n) {
    if (n < 2) return 0; // No duplicates possible with 1 or 0 elements

    // Sort array to make duplicate check easier
    qsort(arr, n, sizeof(int), compare_int);  // You need a simple comparator for ints

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return 1; // Duplicate found
        }
    }
    return 0;
}

