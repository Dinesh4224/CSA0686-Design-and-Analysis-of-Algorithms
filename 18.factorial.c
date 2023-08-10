#include <stdio.h>
#include <time.h>

unsigned long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return factorial(n - 1) * n;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    clock_t start_time = clock();
    unsigned long long result = factorial(n);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Factorial of %d is: %llu\n", n, result);
    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}

