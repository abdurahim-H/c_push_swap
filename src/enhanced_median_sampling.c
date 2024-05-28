/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enhanced_median_sampling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:33:11 by abhudulo          #+#    #+#             */
/*   Updated: 2024/05/28 19:13:26 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



int quickselect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = (left + right) / 2; // You can use a more sophisticated method
    pivotIndex = partition(arr, left, right, pivotIndex);

    // The pivot is in its final sorted position
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}


// int quickselect(int arr[], int low, int high, int k) {
//     if (low == high) return arr[low];

//     int pivot = arr[low + (high - low) / 2];  // Using the middle element as pivot
//     int lt, gt;
//     three_way_partition(arr, low, high, &lt, &gt, pivot);

//     if (k >= lt && k <= gt) {
//         return arr[k];  // The k-th element is in the range of elements equal to the pivot
//     } else if (k < lt) {
//         return quickselect(arr, low, lt - 1, k);
//     } else {
//         return quickselect(arr, gt + 1, high, k);
//     }
// }

// int select_median(int *arr, int left, int right) {
//     int center = (left + right) / 2;
//     // Order the left, center, and right elements
//     if (arr[left] > arr[center])
//         swap(&arr[left], &arr[center]);
//     if (arr[left] > arr[right])
//         swap(&arr[left], &arr[right]);
//     if (arr[center] > arr[right])
//         swap(&arr[center], &arr[right]);

//     // Place the pivot at position right - 1
//     swap(&arr[center], &arr[right - 1]);
//     return arr[right - 1];
// }

int select_median(int arr[], int n) {
    return quickselect(arr, 0, n - 1, n / 2);
}
