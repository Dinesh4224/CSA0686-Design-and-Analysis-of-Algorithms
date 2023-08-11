#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;
    return head;
}

void insertInMiddle(struct Node* prevNode, int num) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertAtEnd(struct Node* head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int i;
    
    head = insertAtBeginning(head, 3);
    printf("List after inserting 3 at the beginning: ");
    printList(head);
    
    insertInMiddle(head, 5);
    printf("List after inserting 5 in the middle: ");
    printList(head);
    
    insertAtEnd(head, 7);
    printf("List after inserting 7 at the end: ");
    printList(head);
    
    struct Node* temp = head;
    for ( i = 0; i < 4; i++) {
        if (temp == NULL) {
            printf("Position not available.\n");
            break;
        }
        temp = temp->next;
    }
    if (temp != NULL) {
        insertInMiddle(temp, 10);
        printf("List after inserting 10 at position 5: ");
        printList(head);
    }
    
    return 0;
}

