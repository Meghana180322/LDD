#include <stdio.h> // Including header file for printf and scanf functions

void assen(int arr[], int size) { // Defining a function for ascending order
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void decs(int arr[], int size) { // Defining a function for descending order
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort(int arr[], int size, void (*callback)(int[], int)) {
    callback(arr, size); // Calls the sorting function (ascending or descending)
}

int main() {
    int input[5] = {5, 3, 1, 4, 2};
    int size = 5;

    sort(input, size, decs); // Sort the array in descending order
    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
    return 0;
}

