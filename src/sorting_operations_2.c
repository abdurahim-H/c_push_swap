/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:06:00 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 20:51:17 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a, t_command **cmd_list)
{
    if (a->size > 1) {
        rotate_stack(a);
        add_command(cmd_list, "ra\n");
    }
}

void rb(t_stack *b, t_command **cmd_list)
{
    if (b->size > 1) {
        rotate_stack(b);
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
        reverse_rotate_stack(a);
        add_command(cmd_list, "rra\n");
    }
}

void rrb(t_stack *b, t_command **cmd_list)
{
    if (b->size > 1) {
        reverse_rotate_stack(b);
        add_command(cmd_list, "rrb\n");
    }
}

void rrr(t_stack *a, t_stack *b, t_command **cmd_list)
{
    rra(a, cmd_list);
    rrb(b, cmd_list);
}