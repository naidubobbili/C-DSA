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

// Function to calculate the sum of all elements in the linked list
int sumOfElements(struct Node* head) {
    // your code
    int i =0;
    struct Node* current = head;
    while(current!=NULL){
        i+=current->data;
        current = current->next;
        }
        return i;

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
    int sum = sumOfElements(head);
    printf("Sum of all elements: %d\n", sum);
    return 0;
}
