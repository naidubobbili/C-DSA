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
    struct Node* newNode;
    for (int i = 1; i < size; i++) {
        newNode=createNode(arr[i]);
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

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    // your code
    newNode->next=head;
    head->prev=newNode;
    head = newNode;
    

    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    // your code
   struct Node* current = head;
   while(current->next!=NULL){
       current=current->next;
       }
       
       newNode->prev=current;
       current->next=newNode;

    return head;
}

// Function to insert a node at a specific position in the doubly linked list (0-based index)
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    // your code
    struct Node* current = head;
    struct Node* newNode = createNode(data);
    int i = 1;
    while(i<position){
        current = current -> next; 
        i++;
        }
     newNode->next=current->next;
     current->next=newNode;
     newNode->prev=current;
     newNode->next->prev=newNode;
     
        

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
            printf("Enter new node value: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;
        case 2:
            printf("Enter new node value: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;
        case 3:
            printf("Enter position (0-based index): ");
            scanf("%d", &position);
            printf("Enter new node value: ");
            scanf("%d", &value);
            head = insertAtPosition(head, value, position);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return 1;
    }
    displayDoublyLinkedListReverse(head);

    return 0;
}