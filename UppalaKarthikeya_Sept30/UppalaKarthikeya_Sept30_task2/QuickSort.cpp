#include "QuickSort.h"

int partition(int arr[], int start, int end) {
    int pivot = arr[start];        // first element as pivot
    int left = start;
    int right = end;

    while (left < right) {
        // Move right pointer leftwards until finding element < pivot
        while (arr[right] >= pivot && left < right) {
            right--;
        }
        if (left < right) {
            arr[left] = arr[right]; // place smaller element on left side
            left++;
        }

        // Move left pointer rightwards until finding element > pivot
        while (arr[left] <= pivot && left < right) {
            left++;
        }
        if (left < right) {
            arr[right] = arr[left]; 
            right--;
        }
    }


    arr[left] = pivot;
    return left; // pivot index
}

// Recursive quicksort function
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        
        int pivotIndex = partition(arr, start, end);

        quickSort(arr, start, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, end);
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
