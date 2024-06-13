/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:06:00 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/13 10:20:30 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *stack_a, t_command **cmd_list) {
    if (stack_a->size >= 2) {
        int value = stack_a->top->value;
        pop(stack_a, NULL);
        push_bottom(stack_a, value);
        add_command(cmd_list, "ra\n");
    }
}

void rb(t_stack *stack_b, t_command **cmd_list) {
    if (stack_b->size >= 2) {
        int value = stack_b->top->value;
        pop(stack_b, NULL);
        push_bottom(stack_b, value);
        add_command(cmd_list, "rb\n");
    }
}

void rr(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
    ra(stack_a, cmd_list);
    rb(stack_b, cmd_list);
}

void rra(t_stack *stack_a, t_command **cmd_list) {
    if (stack_a->size >= 2) {
        int value = stack_a->bottom->value;
        pop_bottom(stack_a, NULL);
        push(stack_a, value);
        add_command(cmd_list, "rra\n");
    }
}

void rrb(t_stack *stack_b, t_command **cmd_list) {
    if (stack_b->size >= 2) {
        int value = stack_b->bottom->value;
        pop_bottom(stack_b, NULL);
        push(stack_b, value);
        add_command(cmd_list, "rrb\n");
    }
}

void rrr(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
    rra(stack_a, cmd_list);
    rrb(stack_b, cmd_list);
}