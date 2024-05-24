/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:12:31 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/24 03:48:49 by abhudulo         ###   ########.fr       */
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

void	pa(t_stack *a, t_stack *b)
{
	int	item;

	if (b->top > 0)
	{
		item = pop(b);
		push(a, item);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	item;

	if (a-> top >= 0)
	{
		item = pop(a);
		push(b, item);
	}
}
