#include <stdio.h>
#include <stdlib.h>

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
    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
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

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    // your code
struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            result = insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            result = insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                result = insertTerm(result, sumCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    int numTerms, coeff, exp;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }
    
    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    // Add the polynomials
    struct Node* sum = addPolynomials(poly1, poly2);

    // Print the result
    printf("Sum of polynomials: ");
    printPolynomial(sum);

    return 0;
}
