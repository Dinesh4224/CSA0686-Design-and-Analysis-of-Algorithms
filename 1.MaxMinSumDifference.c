#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort in ascending order
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int m, n;
    printf("Enter the value of M: ");
    scanf("%d", &m);
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (m > size || n > size || m < 1 || n < 1) {
        printf("Invalid values of M or N.\n");
        return 1;
    }

    // Sort the array in ascending order
    selectionSort(arr, size);

    int mthMax = arr[size - m];
    int nthMin = arr[n - 1];

    int sum = mthMax + nthMin;
    int diff = mthMax - nthMin;

    printf("M-th maximum: %d\n", mthMax);
    printf("N-th minimum: %d\n", nthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);

    return 0;
}

