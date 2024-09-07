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

// Function to create a circular linked list from an array
struct Node* createCircularLinkedList(int arr[], int size) {
   // your code
if(size==0){return NULL;}
else{
    struct Node* head = createNode(arr[0]);
    struct Node * current = head;
    int i = 1;
    while(i<=size){
        current -> next = createNode(arr[i]);
        current = current -> next;
        i++;
        }
       current->next=head;
       return head;
    }
    

}

// Function to display the circular linked list
void displayCircularLinkedList(struct Node* head) {
    // your code
    struct Node* current = head;
    while(current->next != head){
        printf("%d -> ",current->data);
        current = current -> next;
        }
        
        printf("%d (head)",head->data);

}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    printf("Enter array elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* head = createCircularLinkedList(arr, size);
    displayCircularLinkedList(head);
    return 0;
}