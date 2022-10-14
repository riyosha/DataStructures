#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

void free_list(node* head);


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
        printf(p==head?"%d":(p->next==NULL?", %d\n":", %d"), p->val);
        p = p->next;
    }

    return 0;

}

void free_list(node* head) {

    while(head!=NULL){
        node* prev=head;
        head=head->next;
        free(prev);
    }
}
