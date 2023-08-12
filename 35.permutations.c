 #include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int arr[], int start, int end) {
	int i;
    if (start == end) {
        for (i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        generatePermutations(arr, start + 1, end);
        swap(&arr[start], &arr[i]);  
    }
}

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All possible permutations:\n");
    generatePermutations(arr, 0, n - 1);

    return 0;
}

