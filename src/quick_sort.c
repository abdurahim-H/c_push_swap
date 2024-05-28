/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:03:14 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 17:36:38 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *s, const char *name) {
    printf("%s stack contents at top %d: ", name, s->top);
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}


void execute_pb(t_stack *a, t_stack *b) {
    if (a->top >= 0) {  // Ensure there's at least one element in stack A
        int item = pop(a);  // Pop the top item from stack A
        push(b, item);  // Push the popped item onto stack B
        printf("Pushed %d to B\n", item);
    }
}

void execute_pa(t_stack *a, t_stack *b) {
    if (b->top >= 0) {  // Ensure there's at least one element in stack B
        int item = pop(b);  // Pop the top item from stack B
        push(a, item);  // Push the popped item onto stack A
        printf("Pushed %d to A\n", item);
    }
}

void execute_ra(t_stack *a) {
    if (a->top > 0) {  // Ensure there are at least two elements to rotate
        int top_item = a->elements[a->top];  // Save the top item
        for (int i = a->top; i > 0; i--) {
            a->elements[i] = a->elements[i - 1];  // Shift elements upwards
        }
        a->elements[0] = top_item;  // Place the original top item at the start
        printf("Rotated A upwards\n");
    }
}

// int partition(int *arr, int left, int right) {
//     int pivotIndex = select_median(arr, left, right); // Using a median function to select pivot
//     int pivotValue = arr[pivotIndex];
//     swap(&arr[pivotIndex], &arr[right]);  // Move pivot to end
//     int storeIndex = left;
//     for (int i = left; i < right; i++) {
//         if (arr[i] < pivotValue) {
//             swap(&arr[i], &arr[storeIndex]);
//             storeIndex++;
//         }
//     }
//     swap(&arr[storeIndex], &arr[right]);  // Move pivot to its final place
//     return storeIndex;
// }

int partition(int *arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]);  // Move pivot to the end
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[right]);  // Move pivot to its final place
    return storeIndex;
}


void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivotIndex = (left + right) / 2; // Or use a more sophisticated method
        pivotIndex = partition(arr, left, right, pivotIndex);
        quick_sort(arr, left, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, right);
    }
}

// void three_way_partition(int arr[], int low, int high, int *i, int *j) {
//     // This function partitions arr[] in three parts:
//     // arr[low...*i] contains all elements smaller than pivot
//     // arr[*i+1...*j-1] contains all occurrences of pivot
//     // arr[*j...high] contains all elements greater than pivot

//     if (high - low <= 1) {
//         if (arr[high] < arr[low])
//             swap(&arr[high], &arr[low]);
//         *i = low;
//         *j = high;
//         return;
//     }

//     int mid = low;
//     int pivot = arr[high];
//     while (mid <= high) {
//         if (arr[mid] < pivot) {
//             swap(&arr[low++], &arr[mid++]);
//         } else if (arr[mid] == pivot) {
//             mid++;
//         } else if (arr[mid] > pivot) {
//             swap(&arr[mid], &arr[high--]);
//         }
//     }

//     // Update i and j to the last position of the elements less than and greater than pivot
//     *i = low - 1;
//     *j = mid; // or high + 1
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = low;
//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             swap(&arr[i], &arr[j]);
//             i++;
//         }
//     }
//     swap(&arr[i], &arr[high]);
//     return i;
// }

// void quick_sort(int arr[], int low, int high) {
//     if (low < high) {
//         int i, j;
//         three_way_partition(arr, low, high, &i, &j);
//         quick_sort(arr, low, i);
//         quick_sort(arr, j, high);
//     }
// }

// void three_way_partition(int arr[], int low, int high, int *lt, int *gt, int pivot) {
//     int i = low;
//     *lt = low;
//     *gt = high;
//     while (i <= *gt) {
//         if (arr[i] < pivot) {
//             swap(&arr[i], &arr[*lt]);
//             (*lt)++;
//             i++;
//         } else if (arr[i] > pivot) {
//             swap(&arr[i], &arr[*gt]);
//             (*gt)--;
//         } else {
//             i++;
//         }
//     }
// }

// void quick_sort(int arr[], int low, int high) {
//     if (low < high) {
//         int pivot = arr[low + (high - low) / 2];  // Using the middle element as the pivot
//         int lt, gt;
//         three_way_partition(arr, low, high, &lt, &gt, pivot);

//         // Recursively sort elements smaller than the pivot
//         quick_sort(arr, low, lt - 1);

//         // Recursively sort elements greater than the pivot
//         quick_sort(arr, gt + 1, high);
//     }
// }