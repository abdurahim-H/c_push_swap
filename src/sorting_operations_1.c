/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:12:31 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 03:14:11 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a, t_command **cmd_list)
{
    if (a->size > 1) {
        t_node *first = a->top;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        if (first->next) {
            first->next->prev = first;
        }
        second->prev = NULL;
        first->prev = second;
        a->top = second;
        add_command(cmd_list, "sa\n");
    }
}

void sb(t_stack *b, t_command **cmd_list)
{
    if (b->size > 1) {
        t_node *first = b->top;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        if (first->next) {
            first->next->prev = first;
        }
        second->prev = NULL;
        first->prev = second;
        b->top = second;
        add_command(cmd_list, "sb\n");
    }
}

void ss(t_stack *a, t_stack *b, t_command **cmd_list)
{
    sa(a, cmd_list);
    sb(b, cmd_list);
}

void pa(t_stack *a, t_stack *b, t_command **cmd_list)
{
    if (b->size > 0) {
        int value = pop(b);
        push(a, value);
        add_command(cmd_list, "pa\n");
    }
}

void pb(t_stack *a, t_stack *b, t_command **cmd_list)
{
    if (a->size > 0) {
        int value = pop(a);
        push(b, value);
        add_command(cmd_list, "pb\n");
    }
}