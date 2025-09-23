#include "BucketSort.h"
#include <iostream>

int main() {
    int arr[] = {97, 3, 100, 56, 23, 45, 12, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bucketSort(arr, size);

    std::cout << "Sorted Array:   ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
