/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/06/13 16:12:11 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int push_swap_error = 0;

void free_commands(t_command *cmd_list) {
    t_command *current = cmd_list;
    while (current) {
        t_command *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 0;
    }

    t_stack a, b;
    t_command *cmd_list = NULL;
    int capacity = argc - 1;

    init_stack(&a, capacity);
    init_stack(&b, capacity);

    if (process_args(argc, argv, &a)) {
        printf("Error: Invalid input or duplicate values detected.\n");
        free_stack(&a);
        free_stack(&b);
        return 1;
    }

    if (check_duplicates(&a)) {
        printf("Error: Duplicate values are not allowed.\n");
        free_stack(&a);
        free_stack(&b);
        return 1;
    }

    if (is_reverse_sorted(&a)) {
        free_stack(&a);
        free_stack(&b);
        return 0;
    }

    sort_stack(&a, &b, &cmd_list);
    print_commands(cmd_list);

    // Print the final sorted stack
    // t_node *node = a.top;
    // printf("Sorted stack: ");
    // while (node) {
    //     printf("%d ", node->value);
    //     node = node->next;
    // }
    // printf("\n");

    free_commands(cmd_list);
    free_stack(&a);
    free_stack(&b);

    return 0;
}
