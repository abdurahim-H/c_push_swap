/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:03:14 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/13 13:06:27 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int is_reverse_sorted(t_stack *stack) {
	if (stack->size < 2) {
		return 1;
	}
	t_node *current = stack->top;
	while (current->next) {
		if (current->value < current->next->value) {
			return 0;
		}
		current = current->next;
	}
	return 1;
}

void sort_stack(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
	if (check_duplicates(stack_a)) {
        printf("Error: Duplicate values are not allowed.\n");
        return;
    }
	if (is_sorted(stack_a)) {
		if (is_reverse_sorted(stack_a)) {
			// Reverse sorted list, perform ra operations until sorted
			while (!is_sorted(stack_a)) {
				ra(stack_a, cmd_list);
			}
		}
		// Already sorted list, no operations needed
		return;
	}

	while (!is_sorted(stack_a)) {
		// Find the minimum value in stack_a
		int min_value = stack_a->top->value;
		int min_index = 0;
		t_node *current = stack_a->top;
		int index = 0;

		while (current) {
			if (current->value < min_value) {
				min_value = current->value;
				min_index = index;
			}
			current = current->next;
			index++;
		}

		// Rotate stack_a until the minimum value is at the top
		if (min_index <= stack_a->size / 2) {
			while (min_index-- > 0) {
				ra(stack_a, cmd_list);
			}
		} else {
			while (min_index++ < stack_a->size) {
				rra(stack_a, cmd_list);
			}
		}

		// Push the minimum value to stack_b
		pb(stack_a, stack_b, cmd_list);
	}

	// Push all elements from stack_b back to stack_a
	while (stack_b->size > 0) {
		pa(stack_a, stack_b, cmd_list);
	}
}

int is_sorted(t_stack *stack) {
	if (stack->size < 2) {
		return 1;
	}
	t_node *current = stack->top;
	while (current->next) {
		if (current->value > current->next->value) {
			return 0;
		}
		current = current->next;
	}
	return 1;
}

void optimize_stack(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list) {
    if (stack_a->size >= 2 && stack_a->top->value > stack_a->top->next->value) {
        sa(stack_a, cmd_list);
    }
    if (stack_a->size > 0 && stack_b->size > 0 && stack_a->top->value > stack_b->top->value) {
        ss(stack_a, stack_b, cmd_list);
    }
    if (stack_a->size > 1 && stack_b->size > 0 && stack_a->bottom->value < stack_b->top->value) {
        rra(stack_a, cmd_list);
    }
    if (stack_a->size > 0 && stack_b->size > 1 && stack_b->bottom->value > stack_a->top->value) {
        rrb(stack_b, cmd_list);
    }
    while (stack_a->size > 0 && stack_b->size >= 2) {
        if (stack_b->top->value < stack_b->top->next->value) {
            sb(stack_b, cmd_list);
        } else {
            pa(stack_a, stack_b, cmd_list);
        }
    }
}