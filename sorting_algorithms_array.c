#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void SelectionSort(int a[], int size);
void InsertionSort(int a[], int size);
int partition(int a[], int low, int high);
void QuickSort(int a[], int low, int high);
void swap(int *c, int *b);

int main () {

    srand(time(NULL));//in case random generation of array is used
    //user input for size of array
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    while(size<1) {printf("Error. Please enter a positive size of the array: "); scanf("%d", &size);}

    int array[size];
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

    char sorting_method;
    printf("\n\nSelect sorting method - Selection(s), Insertion (i), Quick (q) : ");
    scanf(" %c", &sorting_method);

    if (sorting_method == 's') {
        SelectionSort(array, size);
        printf("\nThe selection sorted array is: ");
        for (int j = 0; j < size; j++) {printf(j?", %i":"%i", array[j]);}
    } else if (sorting_method == 'i') {
        InsertionSort(array, size);
        printf("\nThe insertion sorted array is: ");
        for (int j = 0; j < size; j++) {printf(j?", %i":"%i", array[j]);}
    } else if (sorting_method == 'q') {
        QuickSort(array, 0, size-1);
        printf("\nThe quick sorted array is: ");
        for (int j = 0; j < size; j++) {printf(j?", %i":"%i", array[j]);}
    }
    

}

void swap (int* c,int* b) {
    int temp = *c;
    *c = *b;
    *b = temp;
}

void SelectionSort(int a[], int size) {
    int min_index=0;
    for (int i = 0; i < size; i++) { //with each iteration, array gets smaller by one element
        min_index = i; 
        for(int j = i + 1; j < size; j++) {
            if (a[j] < a[min_index]) {
                min_index = j; 
            }   
        }
        if(min_index!= i) swap(&a[i], &a[min_index]); //if a[i] < a[min_index], their values are swapped in array
    }
}

void InsertionSort(int a[], int size) {
    for (int i=1; i<size; i++) {//increases j by one in each iteration
        for (int j = i-1; j>=0; j--) {//compares element j with all prev element and swaps if out of order
            if (a[j+1]<a[j]) {swap(&a[j+1], &a[j]);}
        }
    }
}

int partition(int a[], int low, int high) {//code puts a[low] in its correct position
    int pivot = a[low];
    int i = low+1;
    int j = high;
    while(i<j) {if (a[i]>=pivot) {swap(&a[i], &a[j]); j--;} else {i++;}}
    if (a[j]>=pivot) {swap(&a[low], &a[j-1]); return j-1;} else {swap(&a[low], &a[j]); return j;}
}
void QuickSort(int a[], int low, int high) {

    if (low<high){//puts all a[i]s into their correct positions by recursion
        int position = partition(a, low, high);
        QuickSort(a, low, position-1);
        QuickSort(a, position+1, high);
    }
}