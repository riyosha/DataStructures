#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int a[], int size);
void swap(int *c, int *b);

int main () {

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the element of the array: ");
        scanf("%i", &array[i]);
    }
    
    printf("The original array is: ");
    for (int j = 0; j < size; j++) {
        printf("%i ", array[j]);
    }


    SelectionSort(array, size);

}

void swap (int *c,int *b) {
    int temp = *c;
    *c = *b;
    *b = temp;
}

void SelectionSort(int a[], int size) {

    for (int j = 0; j < size-1; j++) {
        int min_index = j;
        for(int i = j + 1; i < size; i++) {
            if (a[i] < a[min_index]) {
                min_index = i;
            }   
            swap(&a[j], &a[min_index]);
        }
    }

    printf("\nThe sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%i ", a[i]);
    }
    
}

