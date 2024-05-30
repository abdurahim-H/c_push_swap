/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:03:14 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 04:41:41 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list) {
//     if (a->size <= 1) return;

//     int *arr = malloc(a->size * sizeof(int));
//     if (!arr) {
//         perror("Error");
//         exit(EXIT_FAILURE);
//     }
//     t_node *current = a->top;
//     for (int i = 0; i < a->size; i++) {
//         arr[i] = current->value;
//         current = current->next;
//     }
//     int median = find_median(arr, a->size);
//     free(arr);

//     int pushed_to_b = 0;
//     int original_size = a->size;
//     for (int i = 0; i < original_size; i++) {
//         if (a->top->value < median) {
//             pb(a, b, cmd_list);
//             pushed_to_b++;
//         } else {
//             ra(a, cmd_list);
//         }
//     }

//     // Recur on the smaller part in B
//     if (pushed_to_b > 0) {
//         quicksort_stack(b, a, cmd_list);
//     }

//     // Move elements back to A
//     while (b->size > 0) {
//         pa(a, b, cmd_list);
//     }

//     // Recur on the larger part in A
//     if (original_size - pushed_to_b > 1) {
//         quicksort_stack(a, b, cmd_list);
//     }
// }

void push_range(t_stack *stack, t_range range) {
    push(stack, range.low);
    push(stack, range.high);
}

t_range pop_range(t_stack *stack) {
    int high = pop(stack);
    int low = pop(stack);
    t_range range = {low, high};
    return range;
}

void swap_elements(t_stack *a, t_stack *b, t_stack *stack, int index1, int index2, t_command **cmd_list) {
    t_node *node1 = stack->top;
    t_node *node2 = stack->top;
    for (int i = 0; i < index1; i++) {
        node1 = node1->next;
    }
    for (int i = 0; i < index2; i++) {
        node2 = node2->next;
    }

    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;

    // Add the appropriate swap command (sa or sb) to the command list
    if (stack == a) {
        add_command(cmd_list, "sa\n");
    } else if (stack == b) {
        add_command(cmd_list, "sb\n");
    }
}

int get_value_at_index(t_stack *stack, int index) {
    if (index < 0 || index >= stack->size) {
        fprintf(stderr, "Invalid index\n");
        return -1;
    }

    t_node *current = stack->top;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

int partition(t_stack *a, int low, int high, t_command **cmd_list) {
    // Choose the rightmost element as the pivot
    int pivot = get_value_at_index(a, high);
    int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (get_value_at_index(a, j) < pivot)
		{
			i++;
			swap_elements(a, NULL, a, i, j, cmd_list);
		}
	}

    swap_elements(a, NULL, a, i + 1, high, cmd_list);
    return i + 1;
}


void quicksort_stack(t_stack *a, t_command **cmd_list) {
    t_stack stack;
    init_stack(&stack, a->size);

    t_range initial_range = {0, a->size - 1};
    push_range(&stack, initial_range);

    while (stack.size > 0) {
        t_range range = pop_range(&stack);
        int low = range.low;
        int high = range.high;

        if (low < high) {
            int pivot_index = partition(a, low, high, cmd_list);

            t_range left_range = {low, pivot_index - 1};
            push_range(&stack, left_range);

            t_range right_range = {pivot_index + 1, high};
            push_range(&stack, right_range);
        }
    }

    free_stack(&stack);
}

void print_stack(t_stack *stack, const char *name)
{
    printf("%s stack contents (top to bottom): ", name);
    t_node *current = stack->top;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
} 