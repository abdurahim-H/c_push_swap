/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:06:00 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 02:33:47 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a, t_command **cmd_list)
{
    if (a->size > 1) {
        t_node *first = a->top;
        a->top = first->next;
        a->top->prev = NULL;
        first->next = NULL;
        if (a->bottom) {
            a->bottom->next = first;
            first->prev = a->bottom;
        }
        a->bottom = first;
        add_command(cmd_list, "ra\n");
    }
}

void rb(t_stack *b, t_command **cmd_list)
{
    if (b->size > 1) {
        t_node *first = b->top;
        b->top = first->next;
        b->top->prev = NULL;
        first->next = NULL;
        if (b->bottom) {
            b->bottom->next = first;
            first->prev = b->bottom;
        }
        b->bottom = first;
        add_command(cmd_list, "rb\n");
    }
}

void rr(t_stack *a, t_stack *b, t_command **cmd_list)
{
    ra(a, cmd_list);
    rb(b, cmd_list);
}

void rra(t_stack *a, t_command **cmd_list)
{
    if (a->size > 1) {
        t_node *last = a->bottom;
        a->bottom = last->prev;
        a->bottom->next = NULL;
        last->prev = NULL;
        last->next = a->top;
        a->top->prev = last;
        a->top = last;
        add_command(cmd_list, "rra\n");
    }
}

void rrb(t_stack *b, t_command **cmd_list)
{
    if (b->size > 1) {
        t_node *last = b->bottom;
        b->bottom = last->prev;
        b->bottom->next = NULL;
        last->prev = NULL;
        last->next = b->top;
        b->top->prev = last;
        b->top = last;
        add_command(cmd_list, "rrb\n");
    }
}

void rrr(t_stack *a, t_stack *b, t_command **cmd_list)
{
    rra(a, cmd_list);
    rrb(b, cmd_list);
}
