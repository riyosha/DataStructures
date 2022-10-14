#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* reverse_list(node* head);

int main ()   {
    
    //creating head of list and subsequent pointers 
    node* head = NULL;
    node* p, *temp = NULL;

    int i,n;
    printf("enter desired size of list: ");
    scanf("%d", &n);

    //add to list 
    for (i=0; i<n; i++) {

        temp = malloc(sizeof(node));

        printf("enter list value: ");
        scanf("%d", &temp->val);
        temp->next = NULL;

        if (NULL==head) {
            head = temp;
        } else {
            p->next = temp;
        }
        p = temp;

    }

    //prints original list
    p = head;
    printf("Original linked list is: ");
    while ( p != NULL) {
        printf(p==head?"%d":(p->next==NULL?", %d\n":", %d"), p->val);
        p = p->next;
    }

    node* new_head = reverse_list(head);

    node* q = new_head;
    printf("Reversed linked list is: ");
    while ( q != NULL) {
        printf(q == new_head?"%d":" ,%d", q->val);
        q = q->next;
    }

    return 0;

}

node* reverse_list (node* head) {
    node* temp = NULL;
    node* prev = NULL;

    if (head != NULL) {

        //reverses first pair - this is outside loop to set up prev before head
        prev = head;
        temp = head->next;
        head = head->next;
        prev->next = NULL;

        //sets loop for reverses rest of the chain
        while (head != NULL) {
            
            head = head->next;
            temp->next=prev;

            prev = temp;
            temp = head;

        }

        //head = NULL when loop stops. head = prev sets head of chain to the last non-nullpointing node 
        head = prev;


    }

    return head;

}

