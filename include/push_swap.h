/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 03:45:22 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 04:41:50 by abhudulo         ###   ########.fr       */
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
# include <time.h>
# include <stdbool.h>

// typedef struct
// {
// 	int	*elements;
// 	int	size;
// 	int	top;
// }	t_stack;


// typedef struct s_node
// {
//     int value;
//     struct s_node *next;
//     struct s_node *prev;
// } t_node;

// typedef struct s_stack
// {
//     t_node *top;
//     t_node *bottom;
//     int size;
// } t_stack;

// typedef struct s_command
// {
//     char *cmd;
//     struct s_command *next;
// } t_command;

// void	swap(int *a, int *b);
// long	convert_to_long(char *str);
// int		process_args(int argc, char **argv, int *arr);
// // int partition(int *arr, int left, int right, int pivotIndex);
// // int partition(int *arr, int left, int right);
// // int partition(int arr[], int left, int right, int pivotIndex);
// int partition(int *arr, int left, int right, int pivotIndex);
// // int partition(int arr[], int low, int high);
// // int quickselect(int *arr, int left, int right, int k);
// int quickselect(int arr[], int left, int right, int k);
// int		check_duplicates(int arr[], int n);
// void	init_stack(t_stack *stack, int capacity);
// void	push(t_stack *stack, int item);
// int		pop(t_stack *stack);
// void	free_stack(t_stack *stack);
// void	sa(t_stack *a);
// void	sb(t_stack *b);
// void	pa(t_stack *a, t_stack *b);
// void	pb(t_stack *a, t_stack *b);
// void	ra(t_stack *a);
// void	rb(t_stack *b);
// void	rra(t_stack *a);
// void	rrb(t_stack *b);
// void	rrr(t_stack *a, t_stack *b);
// void	rra(t_stack *a);
// void	swap(int *a, int *b);
// // int select_median(int *arr, int left, int right);
// int select_median(int arr[], int n);
// void	print_stack(t_stack *s, const char *name);
// void	execute_pb(t_stack *a, t_stack *b);
// void	execute_pa(t_stack *a, t_stack *b);
// void	execute_ra(t_stack *a);
// int quickselect(int *arr, int left, int right, int k);
// void quick_sort(int *arr, int left, int right);
// // void three_way_partition(int arr[], int low, int high, int *lt, int *gt, int pivot);
// void sort_stacks(t_stack *a, t_stack *b);
// int find_median(t_stack *stack);

// #endif

// typedef struct s_node
// {
//     int value;
//     struct s_node *next;
//     struct s_node *prev; // Added prev pointer for doubly linked list
// } t_node;

// typedef struct s_stack
// {
//     t_node *top;
//     t_node *bottom; // Added bottom pointer to access the bottom of the stack
//     int size;
//     int capacity;
// } t_stack;

// typedef struct s_command {
//     char *command;
//     struct s_command *next;
// } t_command;

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

typedef struct s_range {
    int low;
    int high;
} t_range;

void initialize_stack(t_stack *stack);
void push_stack(t_stack *stack, int value);
int pop_stack(t_stack *stack);
void rotate_stack(t_stack *stack);
void reverse_rotate_stack(t_stack *stack);
void swap_stack(t_stack *stack);
void add_command(t_command **cmd_list, const char *cmd);
void print_commands(t_command *cmd_list);
int find_median(int *arr, int size);
int get_stack_size(t_stack *stack);
// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list);
// void quicksort_stack(t_stack *a, t_stack *b, t_command **cmd_list);
void quicksort_stack(t_stack *a, t_command **cmd_list);
void print_stack(t_stack *stack, const char *name);
void sa(t_stack *a, t_command **cmd_list);
void sb(t_stack *b, t_command **cmd_list);
void ss(t_stack *a, t_stack *b, t_command **cmd_list);
void pa(t_stack *a, t_stack *b, t_command **cmd_list);
void pb(t_stack *a, t_stack *b, t_command **cmd_list);
void ra(t_stack *a, t_command **cmd_list);
void rb(t_stack *b, t_command **cmd_list);
void rr(t_stack *a, t_stack *b, t_command **cmd_list);
void rra(t_stack *a, t_command **cmd_list);
void rrb(t_stack *b, t_command **cmd_list);
void rrr(t_stack *a, t_stack *b, t_command **cmd_list);
int process_args(int argc, char **argv, t_stack *stack);
int compare_int(const void *a, const void *b);
int compare_int(const void *a, const void *b);
void init_stack(t_stack *stack, int capacity);
void free_stack(t_stack *stack);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int check_duplicates(t_stack *stack);
long convert_to_long(const char *str);
void free_commands(t_command *cmd_list);
void partition_stack(t_stack *a, t_stack *b, int median, t_command **cmd_list);

#endif // PUSH_SWAP_H
