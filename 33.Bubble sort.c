 #include<stdio.h>

void BucketSortAlgo(int arr[], int num) {

int i, j;

int array1[num];

for (i=0; i < num; i++) {

array1[i] = 0;

}

for (i=0; i < num; i++) {

(array1[arr[i]])++;

}

for (i=0,j=0; i < num; i++) {

for (; array1[i]>0;(array1[i])--) {

arr[j++] = i;

}

}

}

int main() {

int array[100];

int num;

int i;

printf("Enter the number of elements : ");

scanf("%d",&num);

printf("Enter the %d elements to be sorted:\n",num);

for (i = 0; i < num; i++ ) {

scanf("%d",&array[i]);

}

printf("\nThe array before sorting : \n");

for (i = 0;i < num;i++) {

printf("%d ", array[i]);

}

printf("\nThe array after sorting : \n");

BucketSortAlgo(array, num);

for (i = 0;i < num;i++) {

printf("%d ", array[i]);

}

printf("\n");

return 0;

}
