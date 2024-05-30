/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:10:13 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 21:07:05 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// long convert_to_long(char *str) {
//     char *endptr;
//     long num;

//     errno = 0;
//     num = strtol(str, &endptr, 10);
//     if (str == endptr || *endptr != '\0' || errno == ERANGE || num > INT_MAX || num < INT_MIN) {
//         fprintf(stderr, "Error\n");
//         return -1;
//     }
//     return num;
// }

long convert_to_long(const char *str)
{
    char *endptr;
    long num = strtol(str, &endptr, 10);
    if (*endptr != '\0' || num > INT_MAX || num < INT_MIN) {
        return LONG_MIN;
    }
    return num;
}

int process_args(int argc, char **argv, t_stack *stack) {
    long num;
    for (int i = 1; i < argc; i++) {
        num = convert_to_long(argv[i]);
        if (num == LONG_MIN || num == LONG_MAX) {
            fprintf(stderr, "Error\n");
            return 1;
        }
        push(stack, (int)num);
    }
    if (check_duplicates(stack)) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    return 0;
}

int check_duplicates(t_stack *stack)
{
    int *arr = (int *)malloc(stack->size * sizeof(int));
    if (!arr) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    t_node *current = stack->top;
    for (int i = 0; i < stack->size; i++) {
        arr[i] = current->value;
        current = current->next;
    }
    for (int i = 0; i < stack->size - 1; i++) {
        for (int j = i + 1; j < stack->size; j++) {
            if (arr[i] == arr[j]) {
                free(arr);
                return 1;
            }
        }
    }
    free(arr);
    return 0;
}
