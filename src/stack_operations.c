/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:38:02 by event             #+#    #+#             */
/*   Updated: 2024/06/13 13:04:32 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void init_stack(t_stack *stack, int capacity) {
//     stack->top = NULL;
//     stack->bottom = NULL;
//     stack->size = 0;
//     stack->capacity = capacity;
// }

// void free_stack(t_stack *stack) {
//     t_node *current = stack->top;
//     while (current) {
//         t_node *temp = current;
//         current = current->next;
//         free(temp);
//     }
//     stack->top = NULL;
//     stack->bottom = NULL;
//     stack->size = 0;
// }

// int push(t_stack *stack, int value) {
//     if (stack->size == stack->capacity) {
//         fprintf(stderr, "Stack overflow\n");
//         return 0;
//     }
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node) {
// 		push_swap_error = 1;
//         return 0;
//     }
//     new_node->value = value;
//     new_node->next = stack->top;
//     new_node->prev = NULL;
//     if (stack->top) {
//         stack->top->prev = new_node;
//     } else {
//         stack->bottom = new_node;
//     }
//     stack->top = new_node;
//     stack->size++;
//     return 1;
// }

// int pop(t_stack *stack, int *value) {
//     if (stack->size == 0) {
//         push_swap_error = 1;
//         return 0;
//     }
//     t_node *temp = stack->top;
//     if (value != NULL) {
//         *value = temp->value;
//     }
//     stack->top = stack->top->next;
//     if (stack->top) {
//         stack->top->prev = NULL;
//     } else {
//         stack->bottom = NULL;
//     }
//     free(temp);
//     stack->size--;
//     return 1;
// }

// void push_bottom(t_stack *stack, int value) {
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node) {
//         // Handle memory allocation failure
//         return;
//     }
//     new_node->value = value;
//     new_node->prev = stack->bottom;
//     new_node->next = NULL;
//     if (stack->bottom) {
//         stack->bottom->next = new_node;
//     } else {
//         stack->top = new_node;
//     }
//     stack->bottom = new_node;
//     stack->size++;
// }

// int pop_bottom(t_stack *stack, int *value) {
//     if (stack->size == 0) {
//         return 0;
//     }
//     t_node *temp = stack->bottom;
//     if (value) {
//         *value = temp->value;
//     }
//     stack->bottom = temp->prev;
//     if (stack->bottom) {
//         stack->bottom->next = NULL;
//     } else {
//         stack->top = NULL;
//     }
//     free(temp);
//     stack->size--;
//     return 1;
// }

// void rotate_stack(t_stack *stack) {
//     if (stack->size < 2) return;
//     t_node *first = stack->top;
//     t_node *last = stack->bottom;
//     stack->top = first->next;
//     stack->top->prev = NULL;
//     last->next = first;
//     first->prev = last;
//     first->next = NULL;
//     stack->bottom = first;
// }

// void reverse_rotate_stack(t_stack *stack) {
//     if (stack->size < 2) return;
//     t_node *first = stack->top;
//     t_node *last = stack->bottom;
//     stack->bottom = last->prev;
//     stack->bottom->next = NULL;
//     last->prev = NULL;
//     last->next = first;
//     first->prev = last;
//     stack->top = last;
// }

// void print_stack(t_stack *stack, const char *label) {
//     t_node *current = stack->top;
//     printf("%s: ", label);
//     while (current != NULL) {
//         printf("%d ", current->value);
//         current = current->next;
//     }
//     printf("\n");
// }

void init_stack(t_stack *stack, int capacity) {
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    stack->capacity = capacity;
}

void free_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        t_node *temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

int push(t_stack *stack, int value) {
    if (stack->size == stack->capacity) {
        fprintf(stderr, "Stack overflow\n");
        return 0;
    }
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) {
        push_swap_error = 1;
        return 0;
    }
    new_node->value = value;
    new_node->next = stack->top;
    new_node->prev = NULL;
    if (stack->top) {
        stack->top->prev = new_node;
    } else {
        stack->bottom = new_node;
    }
    stack->top = new_node;
    stack->size++;
    return 1;
}

int pop(t_stack *stack, int *value) {
    if (stack->size == 0) {
        push_swap_error = 1;
        return 0;
    }
    t_node *temp = stack->top;
    if (value != NULL) {
        *value = temp->value;
    }
    stack->top = stack->top->next;
    if (stack->top) {
        stack->top->prev = NULL;
    } else {
        stack->bottom = NULL;
    }
    free(temp);
    stack->size--;
    return 1;
}

void push_bottom(t_stack *stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) {
        // Handle memory allocation failure
        return;
    }
    new_node->value = value;
    new_node->prev = stack->bottom;
    new_node->next = NULL;
    if (stack->bottom) {
        stack->bottom->next = new_node;
    } else {
        stack->top = new_node;
    }
    stack->bottom = new_node;
    stack->size++;
}

int pop_bottom(t_stack *stack, int *value) {
    if (stack->size == 0) {
        return 0;
    }
    t_node *temp = stack->bottom;
    if (value) {
        *value = temp->value;
    }
    stack->bottom = temp->prev;
    if (stack->bottom) {
        stack->bottom->next = NULL;
    } else {
        stack->top = NULL;
    }
    free(temp);
    stack->size--;
    return 1;
}

void rotate_stack(t_stack *stack) {
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

void reverse_rotate_stack(t_stack *stack) {
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

void print_stack(t_stack *stack, const char *label) {
    t_node *current = stack->top;
    printf("%s: ", label);
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}