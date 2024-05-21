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

// Function prototypes for stack operations
void sa(int *stack_a);
void sb(int *stack_b);
// Add other prototypes here

#endif
