#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* random_LinkedList(int size);
node* sorted = NULL;
void swap(int* a, int* b);
void print_LinkedList(node* head);
void free_list(node* head);
void sortedInsert(node* newnode);
node* partition(node* head, node* last);
void SelectionSort_LinkedList(node* head);
void QuickSort_LinkedList(node* head, node* last);
void InsertionSort_LinkedList(node* head);

int main() {

    int n; //number of nodes
    node* head = NULL;
    node* p, *temp;
    printf("enter desired size of list: ");
    scanf("%d", &n);
    while(n<1) {printf("Error. Please enter a positive size of the array: "); scanf("%d", &n);}


    srand (time(NULL));
    //node* head = random_LinkedList(n); -> to be used if randomly generated linked list is desired 
    for (int i=0; i<n; i++) {//user generated linked list 
        temp = malloc(sizeof(node));

        printf("enter list value: ");
        scanf("%d", &temp->val);
        temp->next = NULL;

        if (NULL==head) {head = temp;} 
        else {p->next = temp;}
        p = temp;
    }
    //print original list
    printf("The original list is: ");
    print_LinkedList(head);

    char sorting_method;
    printf("\n\nSelect sorting method - Selection(s), Insertion (i), Quick (q) : ");
    scanf(" %c", &sorting_method);

    printf("The sorted list is: ");
    //print sorted list 
    if (sorting_method=='s') {
        SelectionSort_LinkedList(head);
        print_LinkedList(head);
    } else if (sorting_method=='q') {
        node* last = head;
        while(last->next){last = last->next;}
        QuickSort_LinkedList(head, last);
        print_LinkedList(head);
    } else if (sorting_method=='i') {
        InsertionSort_LinkedList(head);
        print_LinkedList(head);
    }
    return 0;
}

void SelectionSort_LinkedList(node* head) {
    
    node* min = head;
    node* temp = min->next;

    while(min->next) { //in each itiration, smallest number is added to the start of the decreasing linked list
        while(temp) { //temp goes through all the nodes in the list so that they can be compared with min
            if (min->val>temp->val) {swap(&temp->val, &min->val);}
            temp=temp->next;
        }
        min=min->next;
        temp=min->next;
    }
}

node* partition (node* head, node* last) {
    //last node value is considered the pivot value. this code will put the last node in its correct position
    node* temp = head;
    node* front = head;

    while (front!=NULL&&front!=last) {
        if (front->val < last->val) {
            temp = head;
            swap(&(head->val), &(front->val));//swaps node values
            head = head->next; //visits the next node in the first iteretation
        }
        front = front->next; //visits the next node in the second iteration
    }
    swap(&(head->val),&(last->val));//swaps last node value to current node

    return temp;
}
  
void QuickSort_LinkedList(node* head, node* last) {//partitions list then recursively partitions eacg half
    
    if (head==last) {return;}
    
    node* pivot = partition(head, last);
 
    if (pivot&&pivot->next) {QuickSort_LinkedList(pivot->next, last);}
    if (pivot&&head!=pivot) {QuickSort_LinkedList(head, pivot);}
};




void print_LinkedList(node* head) {
        node* p = head;
        while ( p != NULL) {
        printf(p==head?"%d":(p->next==NULL?", %d\n":", %d"), p->val);
        p = p->next;
    }
}

//generates random linked of size n, all values < 1000
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

void sortedInsert(node* new_node)
{
    /* Special case for the head end */
    if (!sorted||sorted->val>=new_node->val) {
        new_node->next = sorted;
        sorted = new_node;
    } else {
        node* current = sorted;
        // Locate the node before the point of insertion
        while (current->next&&current->next->val<new_node->val) {current = current->next;}
        new_node->next = current->next;
        current->next = new_node;
    }
}

void InsertionSort_LinkedList(node* head) {
    
    node* current = head;
    //traverse given linked list and insert every node to sorted linked list
    while (current) {
        node* next = current->next; //store next for next iteration
        sortedInsert(current);//insert current in sorted linked list
        current = next; //update current
    }
    //update head to point to sorted linked list
    head = sorted;
}

//swaps values of two variables
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


//frees list 
void free_list(node* head) {
    node* prev = head;
    while(head->next) {
        head=head->next;
        free(prev);
    }
}
