#include "BucketSort.h"
#include <iostream>
#include <vector>
#include <cmath>

void bucketSort(int arr[], int size) {
    if (size <= 0) return;

    // Find maximum number to know number of digits
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Get number of digits in maxVal
    int maxDigits = 0;
    while (maxVal > 0) {
        maxDigits++;
        maxVal /= 10;
    }

    // Buckets: 10 rows (0-9), size columns
    std::vector<std::vector<int>> buckets(10, std::vector<int>(size, -1));

    // Sorting pass for each digit position
    int divisor = 1;
    for (int pass = 0; pass < maxDigits; pass++) {
        // Clear buckets
        for (int r = 0; r < 10; r++) {
            for (int c = 0; c < size; c++) {
                buckets[r][c] = -1;
            }
        }

    // Distribution pass
    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / divisor) % 10;
        for (int c = 0; c < size; c++) {
            if (buckets[digit][c] == -1) {
                buckets[digit][c] = arr[i];
                break;
            }
        }
    }

        // Gathering pass
        int index = 0;
        for (int r = 0; r < 10; r++) {
            for (int c = 0; c < size; c++) {
                if (buckets[r][c] != -1) {
                    arr[index++] = buckets[r][c];
                }
            }
        }

        divisor *= 10;
    }
}
