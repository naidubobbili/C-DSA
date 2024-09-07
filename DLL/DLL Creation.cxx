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
    //your code
   
    if(size==0){return NULL;}
    
       struct Node* head=createNode(arr[0]);
       struct Node* current = head;
       struct Node* temp;
       int i = 1;
       while(i<size){
        temp=createNode(arr[i]);
        current->next=temp;
        temp->prev=current;
        current=current->next;        
        i++;        
    }
        
        return head;
        

    
}

// Function to display the contents of the doubly linked list in reverse order
void displayDoublyLinkedListReverse(struct Node* head) {
    //your code
    struct Node* current = head;
    while(current->next!=NULL){
        //printf("%d <-> ",current->data);
        current=current->next;
        }
      while(current!=NULL){
          printf("%d <-> ", current->data);
          current = current -> prev;
          }

    printf("NULL\n");
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

    displayDoublyLinkedListReverse(head);

    return 0;
}
