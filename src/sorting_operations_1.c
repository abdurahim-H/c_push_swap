/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:12:31 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/03 03:36:05 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack_a, t_command **cmd_list) {
    if (stack_a->size >= 2) {
        int temp = stack_a->top->value;
        stack_a->top->value = stack_a->top->next->value;
        stack_a->top->next->value = temp;
        add_command(cmd_list, "sa\n");
    }
}

void sb(t_stack *stack_b, t_command **cmd_list) {
    if (stack_b->size >= 2) {
        int temp = stack_b->top->value;
        stack_b->top->value = stack_b->top->next->value;
        stack_b->top->next->value = temp;
        add_command(cmd_list, "sb\n");
    }
}

void ss(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
    sa(stack_a, cmd_list);
    sb(stack_b, cmd_list);
}

// void pa(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
//     if (stack_b->size > 0) {
//         int value = stack_b->top->value;
//         push(stack_a, value);
//         pop(stack_b, NULL);
//         add_command(cmd_list, "pa\n");
// 		printf("After pa: \n");
//         print_stack(stack_a, "stack_a");
//         print_stack(stack_b, "stack_b");
//     }
// }

// void pb(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
//     if (stack_a->size > 0) {
//         int value = stack_a->top->value;
//         push(stack_b, value);
//         pop(stack_a, NULL);
//         add_command(cmd_list, "pb\n");
// 		printf("After pb: \n");
//         print_stack(stack_a, "stack_a");
//         print_stack(stack_b, "stack_b");
//     }
// }

void pb(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
    if (stack_a->size > 0) {
        int value = stack_a->top->value;
        pop(stack_a, NULL);
        push(stack_b, value);
        add_command(cmd_list, "pb\n");
        printf("After pb: \n");
        print_stack(stack_a, "stack_a");
        print_stack(stack_b, "stack_b");
    }
}

void pa(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
    if (stack_b->size > 0) {
        int value = stack_b->top->value;
        pop(stack_b, NULL);
        push(stack_a, value);
        add_command(cmd_list, "pa\n");
        printf("After pa: \n");
        print_stack(stack_a, "stack_a");
        print_stack(stack_b, "stack_b");
    }
}
