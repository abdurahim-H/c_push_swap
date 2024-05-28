/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enhanced_median_sampling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:33:11 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 20:39:30 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_stack(t_stack *stack)
{
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

void add_command(t_command **cmd_list, const char *cmd)
{
    t_command *new_cmd = (t_command *)malloc(sizeof(t_command));
    if (!new_cmd) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    new_cmd->cmd = strdup(cmd);
    if (!new_cmd->cmd) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    new_cmd->next = NULL;
    if (!*cmd_list) {
        *cmd_list = new_cmd;
    } else {
        t_command *temp = *cmd_list;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_cmd;
    }
}

void print_commands(t_command *cmd_list)
{
    t_command *temp = cmd_list;
    while (temp) {
        printf("%s", temp->cmd);
        temp = temp->next;
    }
}

int find_median(int *arr, int size)
{
    qsort(arr, size, sizeof(int), compare_int);
    return arr[size / 2];
}

int compare_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}