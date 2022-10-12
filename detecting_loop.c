#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//create list

typedef struct node {
    int val;
    struct node* next;
} node;

bool detect_loop();

bool detect_loop(node* list_head) {
    node* rabbit = list_head;
    node* tort = list_head;

    while (NULL != ((rabbit->next || rabbit->next->next) && tort->next)) {
        
        rabbit = rabbit->next->next;
        tort = tort->next;

        if (tort == rabbit) {
            return true;
        }  

    }
    return false;
}
