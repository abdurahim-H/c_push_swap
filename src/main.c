/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/05/21 01:36:03 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i +1);
}

void quickSort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int check_duplicates(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < (n -1))
	{
		if (arr[i] == arr[i + 1])
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (process_args(argc, argv));
}