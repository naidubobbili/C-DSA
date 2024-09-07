#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;   // Coefficient
    int exp;     // Exponent
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term in the polynomial
struct Node* insertTerm(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    // Your code
 if (head == NULL){
    head=newNode;
    }
   else{
    struct Node* current = head;
    while(current->next!=NULL){
      current=current->next;  
      
        }
        current->next=newNode;
    }

    
    return head;
}

// Function to display the polynomial
void printPolynomial(struct Node* head) {
    struct Node* current = head;
    //your code
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
  

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int numTerms;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    for (int i = 0; i < numTerms; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    printf("The polynomial is: ");
    printPolynomial(head);

    return 0;
}
