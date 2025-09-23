#include <iostream>
#include "UniqueNumbers.h"
using namespace std;

// Check for duplicates
bool isDuplicate(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return true; // Found duplicate 
        }
    }
    return false;
}

// Display unique values
void displayUnique(int arr[], int size) {
    cout << "\nUnique numbers entered are:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
