/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 03:45:22 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 19:15:57 by abhudulo         ###   ########.fr       */
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

typedef struct
{
	int	*elements;
	int	size;
	int	top;
}	t_stack;


void	swap(int *a, int *b);
long	convert_to_long(char *str);
int		process_args(int argc, char **argv, int *arr);
// int partition(int *arr, int left, int right, int pivotIndex);
// int partition(int *arr, int left, int right);
// int partition(int arr[], int left, int right, int pivotIndex);
int partition(int *arr, int left, int right, int pivotIndex);
// int partition(int arr[], int low, int high);
// int quickselect(int *arr, int left, int right, int k);
int quickselect(int arr[], int left, int right, int k);
int		check_duplicates(int arr[], int n);
void	init_stack(t_stack *stack, int capacity);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	swap(int *a, int *b);
// int select_median(int *arr, int left, int right);
int select_median(int arr[], int n);
void	print_stack(t_stack *s, const char *name);
void	execute_pb(t_stack *a, t_stack *b);
void	execute_pa(t_stack *a, t_stack *b);
void	execute_ra(t_stack *a);
int quickselect(int *arr, int left, int right, int k);
void quick_sort(int *arr, int left, int right);
// void three_way_partition(int arr[], int low, int high, int *lt, int *gt, int pivot);
#endif
