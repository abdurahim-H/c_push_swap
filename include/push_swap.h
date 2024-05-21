#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>


typedef struct {
    int *elements;
    int size;
    int top;
} t_stack;


void	swap(int *a, int *b);
long	convert_to_long(char *str);
int		process_args(int argc, char **argv, int *arr);
int		partition(int arr[], int low, int high);
void	quickSort(int arr[], int low, int high);
int		check_duplicates(int arr[], int n);
void	init_stack(t_stack *stack, int capacity);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);

#endif
