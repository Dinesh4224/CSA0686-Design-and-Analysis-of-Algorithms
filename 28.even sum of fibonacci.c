 #include <stdio.h>

int main() {
    int N,i;
    
    printf("Enter the value of N: ");
    scanf("%d", &N);
    
    int fib[N + 1];  
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    int evenSum = 0;
    
    for (i = 0; i <= N; i += 2) {
        evenSum += fib[i];
    }
    
    printf("Fibonacci series till %d terms:\n", N + 1);
    for (i = 0; i <= N; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
    
    printf("Sum of Fibonacci numbers at even indexes = %d\n", evenSum);
    
    return 0;
}

