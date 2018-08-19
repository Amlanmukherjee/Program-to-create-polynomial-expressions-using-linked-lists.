/*Program to create polynomial expressions using linked lists.
*Category : project
*AUTHOR :: AMLAN MUKHERJEE
*Github link :
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial {
    int coeff;
    int pow;
    struct polynomial * next;
} p;

void create(p **);
void display(p *);
void addition(p **, p *, p *);
void subtraction(p **, p *, p *);

int main(void) {
    int ch;
        p * poly1, * poly2, * poly3;

        printf("Welcome to polynomial program :::");
        printf("\nCreate 1st expression\n");
        create(&poly1);
        printf("\nStored the 1st expression");
        display(poly1);

        printf("\nCreate 2nd expression\n");
        create(&poly2);
        printf("\nStored the 2nd expression");
        display(poly2);

        addition(&poly3, poly1, poly2);
        display(poly3);

        subtraction(&poly3, poly1, poly2);
        display(poly3);

        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
        if(ch == 1)
            main();
    return 0;
}

void create(p ** node) {
    int flag;
    int coeff, pow;
    p * node1;
    node1 = (p *) malloc(sizeof(p));
    *node = node1;
    do {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        node1->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        node1->pow = pow;

        node1->next = NULL;

        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);

        if(flag) {
            node1->next = (p *) malloc(sizeof(p));
            node1 = node1->next;
            node1->next = NULL;
        }
    } while (flag);
}

void display(p * node) {
    printf("\nThe polynomial expression is:              ");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}


void addition(p ** result, p * poly1, p * poly2) {
    p * node1;
    node1 = (p *) malloc(sizeof(p));
    node1->next = NULL;
    *result = node1;

    while(poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            node1->pow = poly1->pow;
            node1->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            node1->pow = poly2->pow;
            node1->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            node1->pow = poly1->pow;
            node1->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if(poly1 && poly2) {
            node1->next = (p *) malloc(sizeof(p));
            node1 = node1->next;
            node1->next = NULL;
        }
    }

    while(poly1 || poly2) {

        node1->next = (p *) malloc(sizeof(p));
        node1 = node1->next;
        node1->next = NULL;

        if(poly1) {
            node1->pow = poly1->pow;
            node1->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            node1->pow = poly2->pow;
            node1->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

    printf("\nAddition Complete");
}

void subtraction(p ** result, p * poly1, p * poly2) {
    p * node1;
    node1 = (p *) malloc(sizeof(p));
    node1->next = NULL;
    *result = node1;

    while(poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            node1->pow = poly1->pow;
            node1->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            node1->pow = poly2->pow;
            node1->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            node1->pow = poly1->pow;
            node1->coeff = poly1->coeff - poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if(poly1 && poly2) {
            node1->next = (p *) malloc(sizeof(p));
            node1 = node1->next;
            node1->next = NULL;
        }
    }

    while(poly1 || poly2) {

        node1->next = (p *) malloc(sizeof(p));
        node1 = node1->next;
        node1->next = NULL;

        if(poly1) {
            node1->pow = poly1->pow;
            node1->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            node1->pow = poly2->pow;
            node1->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

    printf("\nSubtraction Complete");
}
