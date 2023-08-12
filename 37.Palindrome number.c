#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;  
    }
    
    int original = x;
    int reversed = 0;
    
    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    
    return original == reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }
    
    return 0;
}

