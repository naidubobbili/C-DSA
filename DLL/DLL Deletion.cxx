#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly linked list from an array
struct Node* createDoublyLinkedList(int arr[], int size) {
    if (size == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    for (int i = 1; i < size; i++) {
        struct Node* newNode = createNode(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
    }
    return head;
}

// Function to display the contents of the doubly linked list in reverse order
void displayDoublyLinkedListReverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    // Go to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Traverse backward
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to delete the node at the beginning of the doubly linked list
struct Node* deleteAtBeginning(struct Node* head) {
    // your code
    head = head->next;
    head->prev = NULL;
return head;
}

// Function to delete the node at the end of the doubly linked list
struct Node* deleteAtEnd(struct Node* head) {
    // your code
    struct Node* current = head;
    while(current->next->next!=NULL){
        current=current->next;
        }
        current->next=NULL;
        return head;

}

// Function to delete the node at a specific position in the doubly linked list (0-based index)
struct Node* deleteAtPosition(struct Node* head, int position) {
    // your code
    struct Node* current = head;
    int i = 1;
    while(i<position){
        i++;
        current=current->next;
        }
        current->next=current->next->next;
        current->next->prev=current;
        return head;

}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
struct Node* head = createDoublyLinkedList(arr, size);

    int choice, value, position;

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = deleteAtBeginning(head);
            break;
        case 2:
            head = deleteAtEnd(head);
            break;
        case 3:
            printf("Enter position (0-based index): ");
            scanf("%d", &position);
            head = deleteAtPosition(head, position);
            break;
        default:
                printf("Invalid choice. Please try again.\n");
        }
        displayDoublyLinkedListReverse(head);
    return 0;
}
