/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/06/03 01:22:54 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int push_swap_error = 0;

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
        free_stack(&a);
        free_stack(&b);
        return 1;
    }

    if (is_sorted(&a)) {
        free_stack(&a);
        free_stack(&b);
        return 0;
    }

    sort_stack(&a, &b, &cmd_list);
    print_commands(cmd_list);

    free_commands(cmd_list);
    free_stack(&a);
    free_stack(&b);

    return 0;
}