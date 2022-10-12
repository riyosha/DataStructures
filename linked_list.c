#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;


int main() {
    
    //creating head of list and subsequent pointers 
    node* head = NULL;
    node* p, *temp = NULL;

    int i,n;
    printf("enter desired size of list: ");
    scanf("%d", &n);

    //add to list 
    for (i=0; i<n; i++) {

       
        printf("enter list value: ");
        temp = malloc(sizeof(node));

        scanf("%d", &temp->val);
        temp->next = NULL;

        if (NULL==head) {
            head = temp;
        } else {
            p->next = temp;
        }
        p = temp;

    }

    //print list 

    p = head;
    while ( p != NULL) {

        printf("%d\n", p->val);
        p = p->next;

    }

    return 0;

}
