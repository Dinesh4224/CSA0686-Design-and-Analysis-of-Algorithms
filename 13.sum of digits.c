#include <stdio.h>

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
   
int maxSumWithEqualDigitSum(int nums[], int size) {
    int maxSum = -1;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sum_of_digits(nums[i]) == sum_of_digits(nums[j])) {
                int currentSum = nums[i] + nums[j];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
    }

    return maxSum;
}

int main() {
    int nums[5];
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("enter the N value  \n: ");
    printf("enter the integers :");
    for(int i=0;i< 5;i++){
    	scanf("%d",&nums[i]);
	}
    int result = maxSumWithEqualDigitSum(nums, size);
    printf("Maximum value with equal sum of digits: %d\n", result);

    return 0;
}

