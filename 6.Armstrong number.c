#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int originalNum = num;
    int numDigits = 0;
    
    while (num > 0) {
        num /= 10;
        numDigits++;
    }

    num = originalNum;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}

