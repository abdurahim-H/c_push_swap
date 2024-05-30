/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:12:31 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 07:52:13 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sa(t_stack *a, t_command **cmd_list)
// {
//     if (a->size > 1) {
//         t_node *first = a->top;
//         t_node *second = first->next;
//         first->next = second->next;
//         second->next = first;
//         if (first->next) {
//             first->next->prev = first;
//         }
//         second->prev = NULL;
//         first->prev = second;
//         a->top = second;
//         add_command(cmd_list, "sa\n");
//     }
// }

// void sb(t_stack *b, t_command **cmd_list)
// {
//     if (b->size > 1) {
//         t_node *first = b->top;
//         t_node *second = first->next;
//         first->next = second->next;
//         second->next = first;
//         if (first->next) {
//             first->next->prev = first;
//         }
//         second->prev = NULL;
//         first->prev = second;
//         b->top = second;
//         add_command(cmd_list, "sb\n");
//     }
// }

// void ss(t_stack *a, t_stack *b, t_command **cmd_list)
// {
//     sa(a, cmd_list);
//     sb(b, cmd_list);
// }

// void pa(t_stack *a, t_stack *b, t_command **cmd_list)
// {
//     if (b->size > 0) {
//         int value = pop(b);
//         push(a, value);
//         add_command(cmd_list, "pa\n");
//     }
// }

// void pb(t_stack *a, t_stack *b, t_command **cmd_list)
// {
//     if (a->size > 0) {
//         int value = pop(a);
//         push(b, value);
//         add_command(cmd_list, "pb\n");
//     }
// }

void sa(t_stack *a, t_command **cmd_list) {
    if (a->size > 1) {
        t_node *first = a->top;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        if (first->next) {
            first->next->prev = first;
        } else {
            a->bottom = first;
        }
        second->prev = NULL;
        first->prev = second;
        a->top = second;
        add_command(cmd_list, "sa\n");
    }
}

void sb(t_stack *b, t_command **cmd_list) {
    if (b->size > 1) {
        t_node *first = b->top;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        if (first->next) {
            first->next->prev = first;
        } else {
            b->bottom = first;
        }
        second->prev = NULL;
        first->prev = second;
        b->top = second;
        add_command(cmd_list, "sb\n");
    }
}

void ss(t_stack *a, t_stack *b, t_command **cmd_list) {
    sa(a, cmd_list);
    sb(b, cmd_list);
}

void pa(t_stack *a, t_stack *b, t_command **cmd_list) {
    if (b->size > 0) {
        int value;
        if (pop(b, &value)) {
            if (push(a, value)) {
                add_command(cmd_list, "pa\n");
            } else {
                // Push to stack 'a' failed, revert the pop from stack 'b'
                push(b, value);
            }
        }
    }
}

void pb(t_stack *a, t_stack *b, t_command **cmd_list) {
    if (a->size > 0) {
        int value;
        if (pop(a, &value)) {
            if (push(b, value)) {
                add_command(cmd_list, "pb\n");
            } else {
                // Push to stack 'b' failed, revert the pop from stack 'a'
                push(a, value);
            }
        }
    }
}