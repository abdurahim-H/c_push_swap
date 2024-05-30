/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enhanced_median_sampling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:33:11 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/30 09:25:19 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void swap_stack(t_stack *stack)
// {
//     if (stack->size < 2) return;
//     t_node *first = stack->top;
//     t_node *second = first->next;
//     first->next = second->next;
//     if (second->next) {
//         second->next->prev = first;
//     } else {
//         stack->bottom = first;
//     }
//     second->prev = NULL;
//     second->next = first;
//     first->prev = second;
//     stack->top = second;
// }

// void add_command(t_command **cmd_list, const char *command)
// {
//     t_command *new_cmd = (t_command *)malloc(sizeof(t_command));
//     if (!new_cmd) {
//         perror("Error");
//         exit(EXIT_FAILURE);
//     }
//     new_cmd->command = strdup(command);
//     new_cmd->next = NULL;
//     if (!*cmd_list) {
//         *cmd_list = new_cmd;
//     } else {
//         t_command *current = *cmd_list;
//         while (current->next) {
//             current = current->next;
//         }
//         current->next = new_cmd;
//     }
// }

// void free_commands(t_command *cmd_list)
// {
//     while (cmd_list) {
//         t_command *temp = cmd_list;
//         cmd_list = cmd_list->next;
//         free(temp->command);
//         free(temp);
//     }
// }

void swap_stack(t_stack *stack) {
    if (stack->size < 2) return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    if (second->next) {
        second->next->prev = first;
    } else {
        stack->bottom = first;
    }
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->top = second;
}

void add_command(t_command **cmd_list, const char *command) {
    t_command *new_cmd = (t_command *)malloc(sizeof(t_command));
    if (!new_cmd) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    new_cmd->command = strdup(command);
    new_cmd->next = NULL;
    if (!*cmd_list) {
        *cmd_list = new_cmd;
    } else {
        t_command *current = *cmd_list;
        while (current->next) {
            current = current->next;
        }
        current->next = new_cmd;
    }
}

void free_commands(t_command *cmd_list) {
    while (cmd_list) {
        t_command *temp = cmd_list;
        cmd_list = cmd_list->next;
        free(temp->command);
        free(temp);
    }
}

int compare_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to find the median of an array
int find_median(int *arr, int size)
{
    qsort(arr, size, sizeof(int), compare_int);
    return arr[size / 2];
}
