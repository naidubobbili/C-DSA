#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
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

// Function to create a circular linked list from an array
struct Node* createCircularLinkedList(int arr[], int size) {
    if (size == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    current->next = head;  // Make the list circular
    return head;
}
    
    // Function to display the circular linked list
void displayCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("%d (head)\n", head->data);
}

// Function to delete a node at the beginning of the circular linked list
struct Node* deleteAtBeginning(struct Node* head) {
    // your code
    struct Node* current = head;
    while(current->next!=head){
        current = current->next;
        }
        current->next=current->next->next;
        head=head->next;

    return head;
}

// Function to delete a node at the end of the circular linked list
struct Node* deleteAtEnd(struct Node* head) {
    // your code
    struct Node* current = head;
    while(current->next->next!=head){
        current = current->next;
        }
        current->next=current->next->next;
    
    
return head;
}

// Function to delete a node at a specific position in the circular linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    // your code
    struct Node* current = head;
    int i = 1;
    while(i<position){
        i++;
        current = current->next;
        }
        current->next=current->next->next;
    
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
    struct Node* head = createCircularLinkedList(arr, size);

    int choice, value, position;

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = deleteAtBeginning(head);
            displayCircularLinkedList(head);
            break;
        case 2:
            head = deleteAtEnd(head);
            displayCircularLinkedList(head);
            break;
        case 3:
              printf("Enter position (0-based index): ");
            scanf("%d", &position);
            head = deleteAtPosition(head, position);
            displayCircularLinkedList(head);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;

}
