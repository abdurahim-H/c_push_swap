/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/05/28 20:55:33 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char *argv[])
// {
//     if (argc <= 1) {
//         fprintf(stderr, "Error\n");
//         return 1;
//     }

//     int size = argc - 1;
//     int *arr = (int *)malloc(size * sizeof(int));
//     if (!arr) {
//         fprintf(stderr, "Error\n");
//         return 1;
//     }

//     if (process_args(argc, argv, arr) != 0 || check_duplicates(arr, size)) {
//         free(arr);
//         return 1;
//     }

//     t_stack a, b;
//     initialize_stack(&a);
//     initialize_stack(&b);

//     for (int i = 0; i < size; i++) {
//         push_stack(&a, arr[i]);
//     }

//     free(arr);

//     t_command *cmd_list = NULL;

//     quicksort_stack(&a, &b, &cmd_list);

//     print_commands(cmd_list);
//     print_stack(&a, "A");
//     print_stack(&b, "B");

//     // Free all dynamically allocated memory here

//     return 0;
// }


int main(int argc, char *argv[])
{
	if (argc <= 1) {
		fprintf(stderr, "Error\n");
		return 1;
	}

	int size = argc - 1;
	int *arr = (int *)malloc(size * sizeof(int));
	if (!arr) {
		fprintf(stderr, "Error\n");
		return 1;
	}

	if (process_args(argc, argv, arr) != 0 || check_duplicates(arr, size)) {
		free(arr);
		return 1;
	}

	t_stack a, b;
	initialize_stack(&a);
	initialize_stack(&b);

	for (int i = 0; i < size; i++) {
		push_stack(&a, arr[i]);
	}

	free(arr);

	t_command *cmd_list = NULL;

	quicksort_stack(&a, &b, &cmd_list);

	print_commands(cmd_list);
	print_stack(&a, "A");
	print_stack(&b, "B");

	// Free all dynamically allocated memory here

	return 0;
}