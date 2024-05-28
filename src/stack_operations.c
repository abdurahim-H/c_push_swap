/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:38:02 by event             #+#    #+#             */
/*   Updated: 2024/05/28 20:28:25 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initialize_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

void push_stack(t_stack *stack, int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = stack->top;
    new_node->prev = NULL;
    if (stack->top) {
        stack->top->prev = new_node;
    }
    stack->top = new_node;
    if (!stack->bottom) {
        stack->bottom = new_node;
    }
    stack->size++;
}

int pop_stack(t_stack *stack)
{
    if (!stack->top) {
        fprintf(stderr, "Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int value = stack->top->value;
    t_node *temp = stack->top;
    stack->top = stack->top->next;
    if (stack->top) {
        stack->top->prev = NULL;
    } else {
        stack->bottom = NULL;
    }
    free(temp);
    stack->size--;
    return value;
}

void rotate_stack(t_stack *stack)
{
    if (stack->size < 2) return;
    t_node *first = stack->top;
    t_node *last = stack->bottom;
    stack->top = first->next;
    stack->top->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
    stack->bottom = first;
}

void reverse_rotate_stack(t_stack *stack)
{
    if (stack->size < 2) return;
    t_node *first = stack->top;
    t_node *last = stack->bottom;
    stack->bottom = last->prev;
    stack->bottom->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    stack->top = last;
}
