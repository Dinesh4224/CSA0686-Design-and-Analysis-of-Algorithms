#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compareItems(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    if (ratioA > ratioB) {
        return -1; // Sort in decreasing order of value-to-weight ratio
    } else if (ratioA < ratioB) {
        return 1;
    } else {
        return 0;
    }
}

double fractionalKnapsack(int capacity, struct Item items[], int numItems) {
	int i;
    qsort(items, numItems, sizeof(struct Item), compareItems);
    
    double totalValue = 0.0;
    int currentWeight = 0;
    
    for ( i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)items[i].value * remainingCapacity / items[i].weight;
            break;
        }
    }
    
    return totalValue;
}

int main() {
	int i;
    int capacity, numItems;
    
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    
    struct Item items[numItems];
    
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < numItems; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    double maxTotalValue = fractionalKnapsack(capacity, items, numItems);
    
    printf("Maximum total value in the knapsack: %.2lf\n", maxTotalValue);
    
    return 0;
}

