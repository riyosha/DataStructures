#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* partition (node** head, node* last);
node* QuickSort_LinkedList(node** head, node* last);
void print_LinkedList(node* head);
node* random_LinkedList(int size);

int main() {

    int n; //number of nodes
    printf("enter desired size of list: ");
    scanf("%d", &n);
    while(n<1) {printf("Error. Please enter a positive size of the array: "); scanf("%d", &n);}

    //srand (time(NULL));
    node* head = random_LinkedList(n);

    //print original list
    printf("The original list is: ");
    print_LinkedList(head);

    printf("List partitioned 1 time: ");
    node* x = QuickSort_LinkedList(&head, NULL);
    print_LinkedList(x);
    printf("\n%i", x->val);


}

node* partition (node** head, node* last) {

    node* pivot_position = *head;
    node* temp = (*head)->next;
    node* temp1 = *head;
    int pivot = (*head)->val;

    while (temp!=last&&temp!=NULL) {
        if (temp->val<=pivot) {
            temp1->next=temp->next;
            temp->next=*head;
            *head=temp;
            temp=temp1->next;
        } else if (temp->val>pivot) {
            temp=temp->next;
            temp1=temp1->next;
        }
    }   
    return pivot_position;
}
  
node* QuickSort_LinkedList(node** head, node* last) {
    node* pos = partition(head, last);
    if (pos==*head) {pos=(*head)->next;}
    node* new_head;
    //printf("%i", (*head)->next->val);
    if (pos->next->next!=NULL) {
        printf("%i", pos->val);
        QuickSort_LinkedList(head, pos);
        new_head = pos->next;
        printf("%i", new_head->val);
        QuickSort_LinkedList(&new_head, last);
        pos->next = new_head;
        printf("%i", new_head->val);
        
    }
    return *head;
};

void print_LinkedList(node* head) {
        node* p = head;
        while ( p != NULL) {
        printf(p==head?"%d":(p->next==NULL?", %d\n":", %d"), p->val);
        p = p->next;
    }
}

node* random_LinkedList(int size) {
    //creating head of list and subsequent pointers 
    node* head = NULL;
    node* p, *temp = NULL;

    //add to list 
    for (int i=0; i<size; i++) {

        temp = malloc(sizeof(node));
        temp->val = rand()%1000;
        temp->next = NULL;

        if (NULL==head) {head = temp;} else {p->next = temp;}
        p = temp;
    }
    return head;
}
