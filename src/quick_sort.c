/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:03:14 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 20:53:29 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list)
// {
//     if (a->size <= 1) return;

//     int *arr = (int *)malloc(a->size * sizeof(int));
//     if (!arr) {
//         perror("Error");
//         exit(EXIT_FAILURE);
//     }
//     t_node *current = a->top;
//     for (int i = 0; i < a->size; i++) {
//         arr[i] = current->value;
//         current = current->next;
//     }
//     int median = find_median(arr, a->size);
//     free(arr);

//     int original_size = a->size;
//     for (int i = 0; i < original_size; i++) {
//         if (a->top->value < median) {
//             pb(a, b, cmd_list);
//         } else {
//             ra(a, cmd_list);
//         }
//     }

//     // Sort remaining elements in a
//     while (a->size > original_size / 2) {
//         pb(a, b, cmd_list);
//     }

//     quicksort_stack(a, b, cmd_list);

//     // Move elements back from b to a
//     while (b->size > 0) {
//         pa(a, b, cmd_list);
//     }

//     // Rotate back to original order
//     for (int i = 0; i < original_size / 2; i++) {
//         ra(a, cmd_list);
//     }
// }

// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list) {
//     if (a->size <= 1) return;

//     int *arr = (int *)malloc(a->size * sizeof(int));
//     if (!arr) {
//         perror("Error");
//         exit(EXIT_FAILURE);
//     }
//     t_node *current = a->top;
//     for (int i = 0; i < a->size; i++) {
//         arr[i] = current->value;
//         current = current->next;
//     }
//     int median = find_median(arr, a->size);
//     free(arr);

//     int original_size = a->size;
//     int count = 0;

//     while (count < original_size) {
//         if (a->top->value <= median) {
//             pb(a, b, cmd_list);
//         } else {
//             ra(a, cmd_list);
//         }
//         count++;
//     }

//     while (b->size > 0) {
//         pa(a, b, cmd_list);
//     }

//     // Recursively sort both halves
//     quicksort_stack(a, b, cmd_list);
//     quicksort_stack(b, a, cmd_list);
// }

// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list, int size) {
// 	if (size <= 1) return;

// 	int *arr = (int *)malloc(size * sizeof(int));
// 	if (!arr) {
// 		perror("Error");
// 		exit(EXIT_FAILURE);
// 	}
// 	t_node *current = a->top;
// 	for (int i = 0; i < size; i++) {
// 		arr[i] = current->value;
// 		current = current->next;
// 	}
// 	int median = find_median(arr, size);
// 	free(arr);

// 	int original_size = size;
// 	int count = 0;

// 	while (count < original_size) {
// 		if (a->top->value <= median) {
// 			pb(a, b, cmd_list);
// 			count++;
// 		} else {
// 			ra(a, cmd_list);
// 		}
// 	}

// 	int left_size = count;
// 	int right_size = size - count;

// 	// Recursively sort both halves
// 	quicksort_stack(a, b, cmd_list, left_size);
// 	quicksort_stack(b, a, cmd_list, right_size);
// }

// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list) {
//     if (a->size <= 1) return;

//     int *arr = (int *)malloc(a->size * sizeof(int));
//     if (!arr) {
//         perror("Error");
//         exit(EXIT_FAILURE);
//     }
//     t_node *current = a->top;
//     for (int i = 0; i < a->size; i++) {
//         arr[i] = current->value;
//         current = current->next;
//     }
//     int median = find_median(arr, a->size);
//     free(arr);

//     int original_size = a->size;
//     for (int i = 0; i < original_size; i++) {
//         if (a->top->value < median) {
//             pb(a, b, cmd_list);
//         } else {
//             ra(a, cmd_list);
//         }
//     }

//     // Sort remaining elements in a
//     while (a->size > original_size / 2) {
//         pb(a, b, cmd_list);
//     }

//     quicksort_stack(a, b, cmd_list);

//     // Move elements back from b to a
//     while (b->size > 0) {
//         pa(a, b, cmd_list);
//     }

//     // Rotate back to original order
//     for (int i = 0; i < original_size / 2; i++) {
//         ra(a, cmd_list);
//     }
// }

// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list, int size) {
// 	if (size <= 1) return;

// 	int *arr = (int *)malloc(size * sizeof(int));
// 	if (!arr) {
// 		perror("Error");
// 		exit(EXIT_FAILURE);
// 	}
// 	t_node *current = a->top;
// 	for (int i = 0; i < size; i++) {
// 		arr[i] = current->value;
// 		current = current->next;
// 	}
// 	int median = find_median(arr, size);
// 	free(arr);

// 	int original_size = size;
// 	int count = 0;
// 	for (int i = 0; i < original_size; i++) {
// 		if (a->top->value <= median) {
// 			pb(a, b, cmd_list);
// 			count++;
// 		} else {
// 			ra(a, cmd_list);
// 		}
// 	}

// 	int left_size = count;
// 	int right_size = size - count;

// 	// Recursively sort both halves
// 	quicksort_stack(a, b, cmd_list, left_size);
// 	quicksort_stack(b, a, cmd_list, right_size);

// 	// Move elements back from b to a
// 	while (b->size > 0) {
// 		pa(a, b, cmd_list);
// 	}

// 	// Rotate back to original order
// 	for (int i = 0; i < original_size / 2; i++) {
// 		ra(a, cmd_list);
// 	}
// }

void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list) {
    if (a->size <= 1) return;

    int *arr = (int *)malloc(a->size * sizeof(int));
    if (!arr) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    t_node *current = a->top;
    for (int i = 0; i < a->size; i++) {
        arr[i] = current->value;
        current = current->next;
    }
    int median = find_median(arr, a->size);
    free(arr);

    int original_size = a->size;
    for (int i = 0; i < original_size; i++) {
        if (a->top->value < median) {
            pb(a, b, cmd_list);
        } else {
            ra(a, cmd_list);
        }
    }

    // Sort remaining elements in a
    while (a->size > original_size / 2) {
        pb(a, b, cmd_list);
    }

    quicksort_stack(a, b, cmd_list);

    // Move elements back from b to a
    while (b->size > 0) {
        pa(a, b, cmd_list);
    }

    // Rotate back to original order
    for (int i = 0; i < original_size / 2; i++) {
        ra(a, cmd_list);
    }
}


void print_stack(t_stack *stack, const char *name)
{
    t_node *current = stack->top;
    printf("%s stack contents (top to bottom): ", name);
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}