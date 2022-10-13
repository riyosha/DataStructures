#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* reverse_list(node* head);

int main ()   {
    
    //sample manually made linked-list for testing
    node* head = NULL;
    node* node2 = NULL;
    node* node3 = NULL;

    head = malloc(sizeof(node));
    node2 = malloc(sizeof(node));
    node3 = malloc(sizeof(node));

    head->val = 1;
    head->next=node2;
    node2->val=2;
    node2->next=node3;
    node3->val=3;
    node3->next=NULL;

    //prints original list
    node* q = head;
    while ( q != NULL) {

        printf("%d\n", q->val);
        q = q->next;

    }

    node* new_head = reverse_list(head);

    node* p = new_head;
    while ( p != NULL) {

        printf("%d\n", p->val);
        p = p->next;

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

