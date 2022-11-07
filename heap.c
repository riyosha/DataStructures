/*
    insert
    extractMin
    sift - down, heapify down 
    sift-up, heapify up 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void min_heapify(int a[], int size);
void heapify_down(int a[], int i, int size);
void heapify_up(int a[], int i); 
int insert (int a[], int value, int size);
int extract_min(int a[], int size);
void swap (int* c,int* b);


int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    while(size<1) {printf("Error. Please enter a positive size of the array: "); scanf("%d", &size);}

    int array[MAX];
    int element;

    //user input for elements of array
    for (int i = 0; i < size; i++) {
        printf("Please enter element %i of array: ", i);
        scanf("%i", &element);
        array[i] = element;
    }
    
    //prints original array
    printf("The original array is: ");
    for (int j = 0; j < size; j++) {
        printf(j?", %i":"%i", array[j]);
    }

    min_heapify(array, size);
    printf("\nMin heapify-d array is: ");
    for (int j = 0; j < size; j++) {
        printf(j?", %i":"%i", array[j]);
    }

    char action;
    printf("\n\nSelect action - Extract min(e), Insertion (i): ");
    scanf(" %c", &action);

    if (action=='i') {
        int new_element;
        printf("\nEnter value to be inserted: ");
        scanf("%d", &new_element);
        size = insert(array, new_element, size);
        printf("New heap array after insertion is: ");
        for (int j = 0; j < size; j++) {printf(j?", %i":"%i", array[j]);}
    } else if (action=='e') {
        size = extract_min(array, size);
        printf("\nNew heap array after extracting min value is: ");
        for (int j = 0; j < size; j++) {printf(j?", %i":"%i", array[j]);}
    }
    return 0;
}

void swap (int* c,int* b) {
    int temp = *c;
    *c = *b;
    *b = temp;
}

void min_heapify(int a[], int size) {//uses heapify_i to heapify all elements using bottom up approach
    int i;
    for(i=(size)/2-1; i>=0; i--) {
        heapify_down(a, i, size);
    }
}

void heapify_down(int a[], int i, int size) {//heapifys ith element
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left<size&&a[smallest]>a[left]) {smallest = left;}
    if (right<size&&a[smallest]>a[right]) {smallest = right;}
    if (smallest!=i) {swap(&a[i], &a[smallest]); heapify_down(a, smallest, size);}
}

int extract_min(int a[], int size) {
    int min_value = a[0];
    swap(&a[0], &a[size-1]);
    size = size-1;
    heapify_down(a, 0, size);
    printf("\nMin value is: %i", min_value);

    return size;
}

void heapify_up(int a[], int i) {
    int parent = (i-1)/2;
    if(a[i]<a[parent]) {
        swap(&a[parent], &a[i]);
        heapify_up(a, parent);
    }
}

int insert(int a[], int value, int size) {

    if (size==MAX) {printf("Cannot insert new element, heap is full"); return size;}
    else if (size<MAX) {
        size = size+1;
        a[size-1]=value;
        heapify_up(a, size-1);
    }
    return size;
}