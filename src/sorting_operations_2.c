/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:06:00 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/26 07:04:33 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ra(t_stack *a)
// {
// 	int	i;
// 	int	top_item;

// 	if (a->top > 0)
// 	{
// 		i = a->top;
// 		top_item = pop(a);
// 		while (i >= 0)
// 		{
// 			a->elements[i + 1] = a->elements[i];
// 			i--;
// 		}
// 		a->elements[0] = top_item;
// 	}
// }
// void	rb(t_stack *b)
// {
// 	int	i;
// 	int	top_item;

// 	if (b->top > 0)
// 	{
// 		i = b->top;
// 		top_item = pop(b);
// 		while (i >= 0)
// 		{
// 			b->elements[i + 1] = b->elements[i];
// 			i--;
// 		}
// 		b->elements[0] = top_item;
// 	}
// }

// int ra(t_stack *a)
// {
// 	int i;
// 	int first_item;

// 	if (a->top > 0)
// 	{
// 		first_item = a->elements[0];
// 		for (i = 0; i < a->top - 1; i++)
// 		{
// 			a->elements[i] = a->elements[i + 1];
// 		}
// 		a->elements[a->top - 1] = first_item;
// 	}
// 	return a->top - 1;
// }

// void ra(t_stack *a) {
//     if (a->top > 0) {
//         int first_item = a->elements[0];
//         for (int i = 0; i < a->top; i++) {
//             a->elements[i] = a->elements[i + 1];
//         }
//         a->elements[a->top] = first_item;
//     }
// }

void ra(t_stack *a) {
    if (a->top > 0) {
        int temp = a->elements[0];  // Store the first element
        for (int i = 0; i < a->top; i++) {
            a->elements[i] = a->elements[i + 1];  // Shift elements left
        }
        a->elements[a->top] = temp;  // Put the first element at the end
    }
}

void rb(t_stack *b) {
    if (b->top > 0) {
        int temp = b->elements[0];  // Store the first element
        for (int i = 0; i < b->top; i++) {
            b->elements[i] = b->elements[i + 1];  // Shift elements left
        }
        b->elements[b->top] = temp;  // Put the first element at the end
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
