/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/05/30 09:23:12 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// int main(int argc, char *argv[]) {
//     if (argc <= 1) {
//         fprintf(stderr, "Error\n");
//         return 1;
//     }

//     t_stack a, b;
//     t_command *cmd_list = NULL;
//     int capacity = argc - 1;

//     init_stack(&a, capacity);
//     init_stack(&b, capacity);

//     for (int i = 1; i < argc; i++) {
//         long num = convert_to_long(argv[i]);
//         if (num == LONG_MIN || check_duplicates(&a)) {
//             fprintf(stderr, "Error\n");
//             free_stack(&a);
//             free_stack(&b);
//             return 1;
//         }
//         push(&a, (int)num);
//     }

//     quicksort_stack(&a, &b, &cmd_list);

//     // Print commands
//     t_command *current_cmd = cmd_list;
//     while (current_cmd) {
//         printf("%s", current_cmd->command);
//         current_cmd = current_cmd->next;
//     }

//     // Print the final stacks
//     print_stack(&a, "A");
//     print_stack(&b, "B");

//     free_commands(cmd_list);
//     free_stack(&a);
//     free_stack(&b);

//     return 0;
// }


// int main(int argc, char *argv[]) {
//     if (argc <= 1) {
//         fprintf(stderr, "Usage: %s <numbers to sort>\n", argv[0]);
//         return 1;
//     }
//     if (argc == 2) return 0;

//     t_stack a, b;
//     t_command *cmd_list = NULL;
//     int capacity = argc - 1;

//     init_stack(&a, capacity);
//     init_stack(&b, capacity);

//     for (int i = argc - 1; i >= 1; i--) {
//         int num = atoi(argv[i]);
//         push(&a, num);
//     }

//     printf("Initial stack A: ");
//     print_stack(&a, "A");

//     sort_stack(&a, &b, &cmd_list);

//     printf("Sorted stack A: ");
//     print_stack(&a, "A");

//     t_command *current_cmd = cmd_list;
//     printf("Commands executed:\n");
//     while (current_cmd) {
//         printf("%s\n", current_cmd->command);
//         current_cmd = current_cmd->next;
//     }

//     free_commands(cmd_list);
//     free_stack(&a);
//     free_stack(&b);

//     return 0;
// }

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <numbers to sort>\n", argv[0]);
        return 1;
    }
    if (argc == 2) return 0;

    t_stack a, b;
    t_command *cmd_list = NULL;
    int capacity = argc - 1;

    init_stack(&a, capacity);
    init_stack(&b, capacity);

    for (int i = argc - 1; i >= 1; i--) {
        char *endptr;
        long num = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || num < INT_MIN || num > INT_MAX) {
            fprintf(stderr, "Invalid input: %s\n", argv[i]);
            free_stack(&a);
            free_stack(&b);
            return 1;
        }
        push(&a, (int)num);
    }

    printf("Initial stack A: ");
    print_stack(&a, "A");

    sort_stack(&a, &b, &cmd_list);

    printf("Sorted stack A: ");
    print_stack(&a, "A");

    t_command *current_cmd = cmd_list;
    printf("Commands executed:\n");
    while (current_cmd) {
        printf("%s", current_cmd->command);
        current_cmd = current_cmd->next;
    }

    free_commands(cmd_list);
    free_stack(&a);
    free_stack(&b);

    return 0;
}