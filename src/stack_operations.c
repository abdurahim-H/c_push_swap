/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:38:02 by event             #+#    #+#             */
/*   Updated: 2024/05/21 02:04:14 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *stack, int capacity)
{
	stack -> elements = (int *)malloc(capacity * sizeof(int));
	if (stack -> elements == NULL)
	{
		perror ("Failed to initialize stack");
		return (EXIT_FAILURE);
	}
	stack -> size = capacity;
	stack -> top = -1;
}

void	push(t_stack *stack, int item)
{
	if (stack -> top == stack -> size - 1)
	{
		printf("stack overflow\n");
		return ;
	}
	stack -> elements[++stack->top] = item;
}

int	pop(t_stack *stack)
{
	if (stack -> top == -1)
	{
		printf ("stack underflow\n");
		return (-1);
	}
	return (stack -> elements[stack-> top--]);
}

void free_stack(t_stack *stack)
{
	free(stack -> elements);
	stack -> elements = NULL;
	stack -> top = -1;
	stack -> size = 0;
}