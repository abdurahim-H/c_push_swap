/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 03:45:22 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/13 12:57:23 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack {
    t_node *top;
    t_node *bottom;
    int size;
    int capacity;
} t_stack;

typedef struct s_command {
    char *command;
    struct s_command *next;
} t_command;

extern int push_swap_error;

void init_stack(t_stack *stack, int capacity);
void free_stack(t_stack *stack);
int push(t_stack *stack, int value);
int pop(t_stack *stack, int *value);
void rotate_stack(t_stack *stack);
void reverse_rotate_stack(t_stack *stack);
void swap_stack(t_stack *stack);
void add_command(t_command **cmd_list, const char *cmd);
void free_commands(t_command *cmd_list);
void print_commands(t_command *cmd_list);
void print_stack(t_stack *stack, const char *name);
void push_a(t_stack *a, t_stack *b, t_command **cmd_list);
void push_b(t_stack *a, t_stack *b, t_command **cmd_list);
void sort_stack(t_stack *a, t_stack *b, t_command **cmd_list);
// long convert_to_long(const char *str);
int convert_to_long(const char *str, long *result);
int process_args(int argc, char **argv, t_stack *stack);
// int check_duplicates(t_stack *stack);
bool check_duplicates(t_stack *stack);
int is_sorted(t_stack *stack);
void sa(t_stack *stack_a, t_command **cmd_list);
void sb(t_stack *stack_b, t_command **cmd_list);
void ss(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list);
void pa(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list);
void pb(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list);
void ra(t_stack *stack_a, t_command **cmd_list);
void rb(t_stack *stack_b, t_command **cmd_list);
void rr(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list);
void rra(t_stack *stack_a, t_command **cmd_list);
void rrb(t_stack *stack_b, t_command **cmd_list);
void rrr(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list);
void push_bottom(t_stack *stack, int value);
int pop_bottom(t_stack *stack, int *value);
int is_reverse_sorted(t_stack *stack);
void optimize_stack(t_stack *stack_a, t_stack *stack_b, t_command **cmd_list);

#endif // PUSH_SWAP_H
