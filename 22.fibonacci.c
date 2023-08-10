#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int prev = 1;  
    int curr = 2;  
    int sum = 0;   

    while (curr <= n) {
        if (curr % 2 == 0) {
            sum += curr;
        }

        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    printf("Sum of even Fibonacci numbers up to %d: %d\n", n, sum);

    return 0;
}

