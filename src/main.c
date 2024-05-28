/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:43:47 by event             #+#    #+#             */
/*   Updated: 2024/05/26 12:55:41 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// int main(int argc, char **argv) {
//     if (argc < 2) {
//         printf("Usage: %s <numbers_to_sort>\n", argv[0]);
//         return 1;
//     }

//     int size = argc - 1;
//     int *arr = malloc(size * sizeof(int));
//     if (!arr) {
//         perror("Memory allocation failed");
//         return 2;
//     }

//     // Convert command-line arguments to integers
//     for (int i = 0; i < size; i++) {
//         arr[i] = atoi(argv[i + 1]);
//     }

//     printf("Initial array:\n");
//     print_array(arr, size);

//     // Perform sorting
//     quick_sort(arr, 0, size - 1);

//     printf("Sorted array:\n");
//     print_array(arr, size);

//     free(arr);
//     return 0;
// }

// int main() {
//     // int arr[] = {5, 4, 1, 2, 3, 8, 9};
// 	int arr[] = {42, 17, 93, 8, 71, 11, 33, 19, 37, 88, 5, 26, 20, 44, 66, 76, 14, 23, 29, 55, 98, 27, 61, 79, 31, 85, 7, 38, 50, 64, 13, 22, 34, 46, 58, 70, 82, 94, 6, 18};
// 	int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Initial array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     quick_sort(arr, 0, n - 1);

//     printf("Sorted array:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }


// int main(int argc, char **argv) {
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <num_elements>\n", argv[0]);
//         return 1;
//     }

//     int num_elements = atoi(argv[1]);
//     if (num_elements <= 0) {
//         fprintf(stderr, "Number of elements must be a positive integer\n");
//         return 1;
//     }

//     int *arr = malloc(num_elements * sizeof(int));
//     if (arr == NULL) {
//         perror("Failed to allocate memory for the array");
//         return 1;
//     }

//     // Seed the random number generator
//     srand(time(NULL));

//     printf("Initial array:\n");
//     for (int i = 0; i < num_elements; i++) {
//         arr[i] = rand() % 100;  // Random numbers between 0 and 99
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     quick_sort(arr, 0, num_elements - 1);

//     printf("Sorted array:\n");
//     for (int i = 0; i < num_elements; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     free(arr);
//     return 0;
// }

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    int size = argc - 1;
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("Initial array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}