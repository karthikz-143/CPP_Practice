#include "QuickSort.h"

int main() {
    // Example array
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    // Apply quicksort
    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
