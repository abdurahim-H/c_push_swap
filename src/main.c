/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/05/30 04:42:24 by abhudulo         ###   ########.fr       */
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


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <numbers to sort>\n", argv[0]);
        return 1;
    }

    t_stack a;
    t_command *cmd_list = NULL;
    int capacity = argc - 1;

    init_stack(&a, capacity);

    // Process input numbers and push them onto stack a
    for (int i = 1; i < argc; i++) {
        long num = convert_to_long(argv[i]);
        if (num < INT_MIN || num > INT_MAX || check_duplicates(&a)) {
            fprintf(stderr, "Invalid input or duplicate found.\n");
            free_stack(&a);
            return 1;
        }
        push(&a, (int)num);
    }

    // Print the initial state of stack a
    printf("Initial stack A: ");
    print_stack(&a, "A");

    // Execute the quicksort algorithm
    quicksort_stack(&a, &cmd_list);

    // Print the sorted stack A to verify everything
    printf("Sorted stack A: ");
    print_stack(&a, "A");

    // Optionally, print the commands that were issued
    t_command *current_cmd = cmd_list;
    printf("Commands executed:\n");
    while (current_cmd) {
        printf("%s", current_cmd->command);
        current_cmd = current_cmd->next;
    }

    // Cleanup
    free_commands(cmd_list);
    free_stack(&a);

    return 0;
}