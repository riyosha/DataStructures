#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

void free_list(node* head);
node* push(node* top, int a);
node* pop(node* top);
node* create_node(int a);
void print_LinkedList(node* head);

int main(void) {
    //last node
    node* top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    print_LinkedList(top);
    top = pop(top);
    print_LinkedList(top);
    free(top);
}


node* create_node(int a) {
    node* new = malloc(sizeof(node));
    new->val=a;
    new->next=NULL;
    return new;
}

node* push(node* top, int a) {
    node* new = create_node(a);
    new->next=top;
    top=new;
    return top;
}

node* pop(node* top) {
    node* temp = temp;
    if (!top) {printf("Stack is empty\n");}
    printf("Popped element = %i\n", top->val);
    top=top->next;
    free(temp);
    return top;
}

void free_list(node* head) {

    while(head!=NULL){
        node* prev=head;
        head=head->next;
        free(prev);
    }
}

void print_LinkedList(node* head) {
        node* p = head;
        while ( p != NULL) {
        printf(p==head?"%d":(p->next==NULL?", %d\n":", %d"), p->val);
        p = p->next;
    }
}
