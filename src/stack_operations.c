/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:38:02 by event             #+#    #+#             */
/*   Updated: 2024/05/30 09:24:21 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void push(t_stack *stack, int value)
// {
//     if (stack->size == stack->capacity) {
//         fprintf(stderr, "Stack overflow\n");
//         return;
//     }
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node) {
//         perror("Error");
//         exit(EXIT_FAILURE);
//     }
//     new_node->value = value;
//     new_node->next = stack->top;
//     new_node->prev = NULL; // Initialize prev
//     if (stack->top) {
//         stack->top->prev = new_node; // Set the previous top's prev to new_node
//     }
//     stack->top = new_node;
//     if (stack->size == 0) {
//         stack->bottom = new_node; // Initialize bottom
//     }
//     stack->size++;
// }

// int pop(t_stack *stack)
// {
//     if (stack->size == 0) {
//         fprintf(stderr, "Stack underflow\n");
//         return -1;
//     }
//     t_node *temp = stack->top;
//     int value = temp->value;
//     stack->top = stack->top->next;
//     if (stack->top) {
//         stack->top->prev = NULL; // Update the new top's prev
//     } else {
//         stack->bottom = NULL; // Update bottom if the stack is empty
//     }
//     free(temp);
//     stack->size--;
//     return value;
// }

// void init_stack(t_stack *stack, int capacity)
// {
//     stack->top = NULL;
//     stack->bottom = NULL; // Initialize bottom
//     stack->size = 0;
//     stack->capacity = capacity;
// }
// void free_stack(t_stack *stack)
// {
//     t_node *current = stack->top;
//     while (current) {
//         t_node *temp = current;
//         current = current->next;
//         free(temp);
//     }
//     stack->top = NULL;
//     stack->bottom = NULL; // Free bottom
//     stack->size = 0;
// }

// int push(t_stack *stack, int value) {
//     if (stack->size == stack->capacity) {
//         fprintf(stderr, "Stack overflow\n");
//         return 0; // Return 0 to indicate failure
//     }

//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node) {
//         perror("Error");
//         return 0; // Return 0 to indicate failure
//     }

//     new_node->value = value;
//     new_node->next = stack->top;
//     new_node->prev = NULL;

//     if (stack->top) {
//         stack->top->prev = new_node;
//     } else {
//         stack->bottom = new_node; // Update bottom if the stack was empty
//     }

//     stack->top = new_node;
//     stack->size++;

//     return 1; // Return 1 to indicate success
// }

// int pop(t_stack *stack, int *value) {
//     if (stack->size == 0) {
//         fprintf(stderr, "Stack underflow\n");
//         return 0; // Return 0 to indicate failure
//     }

//     t_node *temp = stack->top;
//     *value = temp->value;

//     stack->top = stack->top->next;
//     if (stack->top) {
//         stack->top->prev = NULL;
//     } else {
//         stack->bottom = NULL; // Update bottom if the stack becomes empty
//     }

//     free(temp);
//     stack->size--;

//     return 1; // Return 1 to indicate success
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
        perror("Error");
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
        fprintf(stderr, "Stack underflow\n");
        return 0;
    }
    t_node *temp = stack->top;
    *value = temp->value;
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

// void rotate_stack(t_stack *stack)
// {
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

// void reverse_rotate_stack(t_stack *stack)
// {
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
