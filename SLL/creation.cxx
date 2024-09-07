
#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to convert an array to a linked list
struct Node* dataToLinkedList(int arr[], int size) {
    // your code
    if (size == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

void printLinkedList(struct Node* head) {
   // your code
   struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    printf("Enter array elements: ", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);  // Read the input and store it in the array
    }
    struct Node* head = dataToLinkedList(arr, size);
    // Print the linked list
    printLinkedList(head);
    return 0;
    
}