/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:03:14 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 09:25:50 by abhudulo         ###   ########.fr       */
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


// void swap_elements(t_stack *a, t_stack *b, t_stack *stack, int index1, int index2, t_command **cmd_list) {
//     if (index1 == 0 && index2 == 1) {
//         // If swapping the top two elements, use sa, sb, or ss
//         if (stack == a && (b == NULL || stack == b)) {
//             sa(a, cmd_list);
//         } else if (stack == b && b != NULL) {
//             sb(b, cmd_list);
//         }
//     } else {
//         // If swapping elements at other positions, swap them directly
//         t_node *node1 = stack->top;
//         t_node *node2 = stack->top;
//         for (int i = 0; i < index1; i++) {
//             node1 = node1->next;
//         }
//         for (int i = 0; i < index2; i++) {
//             node2 = node2->next;
//         }

//         int temp = node1->value;
//         node1->value = node2->value;
//         node2->value = temp;
//     }
// }

// int get_value_at_index(t_stack *stack, int index) {
//     if (index < 0 || index >= stack->size) {
//         fprintf(stderr, "Invalid index\n");
//         return -1;
//     }
//     t_node *current = stack->top;
//     for (int i = 0; i < index; i++) {
//         current = current->next;
//     }
//     return current->value;
// }

int push_range(t_stack *stack, t_range range) {
    if (stack->size + 2 > stack->capacity) {
        fprintf(stderr, "Stack overflow\n");
        return 0; // Return 0 to indicate failure
    }

    if (!push(stack, range.low)) {
        return 0; // Return 0 if pushing the low value fails
    }

    if (!push(stack, range.high)) {
        // If pushing the high value fails, we need to remove the low value
        int temp;
        pop(stack, &temp);
        return 0; // Return 0 to indicate failure
    }

    return 1; // Return 1 to indicate success
}

int pop_range(t_stack *stack, t_range *range) {
    if (stack->size < 2) {
        fprintf(stderr, "Not enough elements to pop a range\n");
        return 0; // Return 0 to indicate failure
    }

    if (!pop(stack, &(range->high))) {
        return 0; // Return 0 if popping the high value fails
    }

    if (!pop(stack, &(range->low))) {
        // If popping the low value fails, we need to push the high value back
        push(stack, range->high);
        return 0; // Return 0 to indicate failure
    }

    return 1; // Return 1 to indicate success
}

void push_a(t_stack *a, t_stack *b, t_command **cmd_list) {
    int value;
    if (pop(b, &value)) {
        push(a, value);
        add_command(cmd_list, "pa\n");
    }
}

void push_b(t_stack *a, t_stack *b, t_command **cmd_list) {
    int value;
    if (pop(a, &value)) {
        push(b, value);
        add_command(cmd_list, "pb\n");
    }
}

void swap_elements(t_stack *a, t_stack *b, t_stack *stack, int index1, int index2, t_command **cmd_list) {
    if (index1 == 0 && index2 == 1) {
        // If swapping the top two elements, use sa, sb, or ss
        if (stack == a && (b == NULL || stack == b)) {
            sa(a, cmd_list);
        } else if (stack == b && b != NULL) {
            sb(b, cmd_list);
        }
    } else {
        // If swapping elements at other positions, swap them directly
        t_node *node1 = stack->top;
        t_node *node2 = stack->top;
        for (int i = 0; i < index1; i++) {
            if (node1 == NULL) break;
            node1 = node1->next;
        }
        for (int i = 0; i < index2; i++) {
            if (node2 == NULL) break;
            node2 = node2->next;
        }
        if (node1 != NULL && node2 != NULL) {
            int temp = node1->value;
            node1->value = node2->value;
            node2->value = temp;
        }
    }
}


int get_value_at_index(t_stack *stack, int index) {
    if (index < 0 || index >= stack->size) {
        fprintf(stderr, "Invalid index\n");
        return 0; // Return a default value or handle the error differently
    }
    t_node *current = stack->top;
    for (int i = 0; i < index; i++) {
        if (current == NULL) break;
        current = current->next;
    }
    if (current != NULL) {
        return current->value;
    } else {
        fprintf(stderr, "Invalid index\n");
        return 0; // Return a default value or handle the error differently
    }
}
int partition(t_stack *a, int low, int high, t_command **cmd_list) {
    // Choose the rightmost element as the pivot
    int pivot = get_value_at_index(a, high);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (get_value_at_index(a, j) < pivot) {
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
    if (!push_range(&stack, initial_range)) {
        fprintf(stderr, "Error initializing stack range\n");
        free_stack(&stack);
        return;
    }

    while (stack.size > 0) {
        t_range range;
        if (!pop_range(&stack, &range)) {
            fprintf(stderr, "Error popping range from stack\n");
            free_stack(&stack);
            return;
        }

        int low = range.low;
        int high = range.high;

        if (low < high) {
            int pivot_index = partition(a, low, high, cmd_list);

            t_range left_range = {low, pivot_index - 1};
            if (!push_range(&stack, left_range)) {
                fprintf(stderr, "Error pushing left range to stack\n");
                free_stack(&stack);
                return;
            }

            t_range right_range = {pivot_index + 1, high};
            if (!push_range(&stack, right_range)) {
                fprintf(stderr, "Error pushing right range to stack\n");
                free_stack(&stack);
                return;
            }
        }
    }

    free_stack(&stack);
}

void print_stack(t_stack *stack, const char *name) {
    printf("%s stack contents (top to bottom): ", name);
    t_node *current = stack->top;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void sort_stack(t_stack *a, t_stack *b, t_command **cmd_list) {
    while (a->size > 0) {
        int min_val = a->top->value;
        int min_index = 0;
        t_node *current = a->top;
        int index = 0;
        while (current) {
            if (current->value < min_val) {
                min_val = current->value;
                min_index = index;
            }
            current = current->next;
            index++;
        }
        if (min_index <= a->size / 2) {
            for (int i = 0; i < min_index; i++) {
                rotate_stack(a);
                add_command(cmd_list, "ra\n");
            }
        } else {
            for (int i = 0; i < a->size - min_index; i++) {
                reverse_rotate_stack(a);
                add_command(cmd_list, "rra\n");
            }
        }
        push_b(a, b, cmd_list);
    }

    while (b->size > 0) {
        push_a(a, b, cmd_list);
    }
}