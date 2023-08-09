#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int low, int high, int *comparisonCount) {
    struct MinMax mm, mmLeft, mmRight, mmMerge;
    int mid;

    if (low == high) {
        mm.min = arr[low];
        mm.max = arr[low];
        return mm;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            mm.min = arr[low];
            mm.max = arr[high];
        } else {
            mm.min = arr[high];
            mm.max = arr[low];
        }
        (*comparisonCount)++;
        return mm;
    }

    mid = (low + high) / 2;
    mmLeft = findMinMax(arr, low, mid, comparisonCount);
    mmRight = findMinMax(arr, mid + 1, high, comparisonCount);

    if (mmLeft.min < mmRight.min) {
        mmMerge.min = mmLeft.min;
    } else {
        mmMerge.min = mmRight.min;
    }
    if (mmLeft.max > mmRight.max) {
        mmMerge.max = mmLeft.max;
    } else {
        mmMerge.max = mmRight.max;
    }

    (*comparisonCount) += 2; 
 
    return mmMerge;
}

int main() {
    int arr[] = {8, -5, 7, 2, 6, 0, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int comparisonCount = 0;
    struct MinMax result = findMinMax(arr, 0, n - 1, &comparisonCount);

    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    printf("Number of comparisons: %d\n", comparisonCount);

    return 0;
}
