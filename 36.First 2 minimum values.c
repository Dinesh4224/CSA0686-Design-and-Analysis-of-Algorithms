#include <stdio.h>
#include <limits.h>

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 1) {
        printf("At least two numbers are required.\n");
        return 1;
    }
    
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2 && num != min1) {
            min2 = num;
        }
    }
    
    printf("The first minimum value: %d\n", min1);
    printf("The second minimum value: %d\n", min2);
    
    return 0;
}

