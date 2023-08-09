#include<stdio.h>

#include<stdlib.h>

#include<conio.h>  

int main()

{

    int array[50],i,target,num;

    printf("How many elements do you want in the array");

    scanf("%d",&num);

    printf("Enter array elements:");

    for(i=0;i<num;++i)

        scanf("%d",&array[i]);

    printf("Enter element to search:");

    scanf("%d",&target);

    for(i=0;i<num;++i)

        if(array[i]==target)

            break;

    if(i<num)

        printf("Target element found at location %d",i);

    else

        printf("Target element not found in an array");

    return 0;

}
