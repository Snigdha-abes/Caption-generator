#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff, pow;
    struct node *next;
};

struct node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

void polyadd(struct node *poly1, struct node *poly2, struct node *poly);
void create(struct node *temp);
void display(struct node *temp);

int main() {
    poly1 = (struct node*)malloc(sizeof(struct node));
    poly2 = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter details for polynomial 1:\n");
    create(poly1);
    
    printf("Enter details for polynomial 2:\n");
    create(poly2);
    
    printf("Polynomial 1:\n");
    display(poly1);
    
    printf("Polynomial 2:\n");
    display(poly2);
    
    poly = (struct node*)malloc(sizeof(struct node));
    polyadd(poly1, poly2, poly);
    
    printf("Sum of Polynomials:\n");
    display(poly);
    
    return 0;
}

void polyadd(struct node *poly1, struct node *poly2, struct node *poly) {
    while (poly1->next != NULL && poly2->next != NULL) {
        if (poly1->pow > poly2->pow) {
            poly->coeff = poly1->coeff;
            poly->pow = poly1->pow;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            poly->coeff = poly2->coeff;
            poly->pow = poly2->pow;
            poly2 = poly2->next;
        } else {
            poly->coeff = poly1->coeff + poly2->coeff;
            poly->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        poly->next = (struct node*)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
    
    while (poly1->next != NULL || poly2->next != NULL) {
        if (poly1->next != NULL) {
            poly->coeff = poly1->coeff;
            poly->pow = poly1->pow;
            poly1 = poly1->next;
        } else {
            poly->coeff = poly2->coeff;
            poly->pow = poly2->pow;
            poly2 = poly2->next;
        }
        
        poly->next = (struct node*)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
}

void create(struct node *temp) {
    char ch;
    do {
        printf("Enter coeff: ");
        scanf("%d", &temp->coeff);
        printf("Enter power: ");
        scanf("%d", &temp->pow);
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void display(struct node *temp) {
    while (temp->next != NULL) {
        printf("%dX^%d + ", temp->coeff, temp->pow);
        temp = temp->next;
    }
    printf("%dX^%d\n", temp->coeff, temp->pow);
}
