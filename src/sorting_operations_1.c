/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:12:31 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 20:51:04 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a, t_command **cmd_list)
{
    if (a->size > 1) {
        swap_stack(a);
        add_command(cmd_list, "sa\n");
    }
}

void sb(t_stack *b, t_command **cmd_list)
{
    if (b->size > 1) {
        swap_stack(b);
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
        push_stack(a, pop_stack(b));
        add_command(cmd_list, "pa\n");
    }
}

void pb(t_stack *a, t_stack *b, t_command **cmd_list)
{
    if (a->size > 0) {
        push_stack(b, pop_stack(a));
        add_command(cmd_list, "pb\n");
    }
}
