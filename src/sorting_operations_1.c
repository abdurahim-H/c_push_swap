/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:12:31 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 19:09:45 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a->top > 0)
		swap(&a->elements[a->top], &a->elements[a->top - 1]);
}

void	sb(t_stack *b)
{
	if (b->top > 0)
		swap(&b->elements[b->top], &b->elements[b->top - 1]);
}

void pb(t_stack *a, t_stack *b) {
	if (a->top >= 0) {  // Check if stack a is not empty
		int element = pop(a);  // Pop an element from stack a
		push(b, element);  // Push the element onto stack b
	} else {
		printf("stack underflow\n");
	}
}

void pa(t_stack *a, t_stack *b) {
	if (b->top >= 0) {  // Check if stack b is not empty
		int element = pop(b);  // Pop an element from stack b
		push(a, element);  // Push the element onto stack a
	} else {
		printf("stack underflow\n");
	}
}
