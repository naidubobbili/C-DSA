#include <stdio.h>
#include <stdlib.h>

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

// Function to convert array to linked list
struct Node* dataToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
    
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    // Your code
    struct Node* current = createNode(data);
        current -> next = head;
        head = current;
        return head;
   
  
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    // Your code
    struct Node* current = head;
    while(current->next!=NULL){
        current = current->next;
        }
        
        current->next=newNode;
        newNode->next=NULL;
        return head;

    
}

// Function to insert a node at a given position (0-based index)
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    // Your code
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int i =1;
    while(i!=position){
        i++;
        current = current->next;
        }
        
        struct Node* temp = current->next;
        current->next=newNode;
        newNode->next=temp;
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
    struct Node* head = dataToLinkedList(arr, size);
    int choice, value, position;
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter new node data: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            printLinkedList(head);
            break;
        case 2:
            printf("Enter new node data: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            printLinkedList(head);
            break;
        case 3:
            printf("Enter position (0-based index): ");
            scanf("%d", &position);
            printf("Enter new node data: ");
            scanf("%d", &value);
            head = insertAtPosition(head, value, position);
            printLinkedList(head);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}
