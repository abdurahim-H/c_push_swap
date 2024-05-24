/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 03:48:00 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/24 03:49:06 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	i;
	int	top_item;

	if (a->top > 0)
	{
		i = a->top;
		top_item = pop(a);
		while (i >= 0)
		{
			a->elements[i + 1] = a->elements[i];
			i--;
		}
		a->elements[0] = top_item;
	}
}
void	rb(t_stack *b)
{
	int	i;
	int	top_item;

	if (b->top > 0)
	{
		i = b->top;
		top_item = pop(b);
		while (i >= 0)
		{
			b->elements[i + 1] = b->elements[i];
			i--;
		}
		b->elements[0] = top_item;
	}
}

void	rra(t_stack *a)
{
	int	i;
	int	last_item;

	if (a->top > 0)
	{
		i = a->top;
		last_item = a->elements[a->top];
		while (i > 0)
		{
			a->elements[i] = a->elements[i - 1];
			i--;
		}
		a->elements[0] = last_item;
	}
}

void	rrb(t_stack *b)
{
	int	i;
	int	last_item;

	if(b->top > 0)
	{
		i = b->top;
		last_item = b->elements[b->top];
		while (i > 0)
		{
			b->elements[i] = b->elements[i - 1];
		}
		b->elements[0] = last_item;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
