#include <stdio.h>

#define SIZE 15

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target) 
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int X[SIZE], A;

    printf("Enter 15 array elements:\n");
    for (int i = 0; i < SIZE; i++)
        scanf_s("%d", &X[i]);

    printf("Enter target element A: ");
    scanf_s("%d", &A);

    int linIndex = linearSearch(X, SIZE, A);
    if (linIndex != -1)
        printf("Linear search: found at position %d\n", linIndex);
    else
        printf("Linear search: not found\n");

    bubbleSortDesc(X, SIZE);

    printf("Sorted array in descending order:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", X[i]);
    printf("\n");

    int binIndex = binarySearch(X, SIZE, A);
    if (binIndex != -1)
        printf("Binary search: found at position %d\n", binIndex);
    else
        printf("Binary search: not found\n");

    return 0;
}
