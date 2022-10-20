#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* ChunkReverse (node* head, int n);
void FreeList(node* head);

int main ()   {

    //declare head of list and subsequent pointers 
    node* head = NULL;
    node* p, *temp = NULL;
    int ChunkSize;
    int i,n;

    printf("Enter desired size of list: ");
    scanf("%d", &n);

    //add nodes to list 
    for (i=0; i<n; i++) {
        temp = malloc(sizeof(node));

        printf("enter list value: ");
        scanf("%d", &temp->val);
        temp->next = NULL;

        if (NULL==head) { head = temp;} 
        else {p->next = temp;}
        p = temp;
    }

    //prints original list
    p = head;
    printf("Original linked list is: ");
    while ( p != NULL) {
        printf(p==head?"%d":(p->next==NULL?", %d\n":", %d"), p->val);
        p = p->next;
    }

    //get user input for chunk size
    printf("Please enter chunk size:");
    scanf("%i", &ChunkSize);

    node* reversed_list = ChunkReverse(head, ChunkSize);

    printf("The chunk reversed list is\n");
    while ( reversed_list != NULL) {

        printf(reversed_list==NULL?"":(reversed_list->next!=NULL?"%d, ":"%d\n"), reversed_list->val);
        reversed_list = reversed_list->next;

    }

    FreeList(reversed_list);

}

node* ChunkReverse(node* head, int n) {

    //int n;
    int count = 0;
    node* current = head;
    node* temp = NULL;
    node* prev = NULL;

    //reverse n nodes of first chunk of the list
    while (NULL!=current && count < n) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp; 
        count++;
    }
    
    if (NULL==current) {
        printf("Please enter valid pointer to a node");
    }

    //recursively make original head of chunk of list point to head of next chunk of list 
    //(head of the next xhunk is the temp pointer)
    if (temp !=NULL) {
        head->next = ChunkReverse(temp, n);
    }

    return prev;
    
}

void FreeList(node* head) {
   
   node* tmp;
   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}
