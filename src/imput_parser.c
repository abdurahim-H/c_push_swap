/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:10:13 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/03 01:23:10 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define HASH_SIZE 10007

int convert_to_long(const char *str, long *result) {
    char *endptr;
    long num = strtol(str, &endptr, 10);
    if (*endptr != '\0' || num > INT_MAX || num < INT_MIN) {
        return 0; // Return 0 to indicate an error
    }
    *result = num;
    return 1; // Return 1 to indicate success
}


int process_args(int argc, char **argv, t_stack *stack) {
    for (int i = 1; i < argc; i++) {
        long num;
        if (!convert_to_long(argv[i], &num)) {
            push_swap_error = 1;
            return 1;
        }
        if (!push(stack, (int)num)) {
            push_swap_error = 1;
            return 1;
        }
    }
    if (check_duplicates(stack)) {
        push_swap_error = 1;
        return 1;
    }
    return 0;
}

bool check_duplicates(t_stack *stack) {
    int *hash_table = (int *)calloc(HASH_SIZE, sizeof(int));
    if (!hash_table) {
        return true; // Memory allocation failed
    }

    t_node *current = stack->top;
    while (current) {
        int value = current->value;
        int hash_index = abs(value) % HASH_SIZE;
        if (hash_table[hash_index] == value) {
            free(hash_table);
            return true; // Duplicate found
        }
        hash_table[hash_index] = value;
        current = current->next;
    }

    free(hash_table);
    return false; // No duplicates
}