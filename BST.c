#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
	struct node* left;
    struct node* right;
} node;

node* create_node(int input);
node* insert_node(node* root, node* temp);
void swap(int* a, int* b);
void print_bst_InOrder(node* root);
void search_node(node* root, int input);
void delete_node(node* root, int input);
void free_bst(node* root);

int main () {

    int n, value;
    node* root = NULL;

    //user input for value of root node
    printf("Please enter value of root node: ");
    scanf("%i", &value);
    root = insert_node(root, create_node(value));
    
    //user input for number of nodes desired 
    printf("How many nodes do you want to add? Enter a positive number: ");
    scanf("%i", &n);

    //asks for user input for new node n times
    //need to ensure that if user enters the same value twice, program asks for a value an extra time
    int input[n];
    for(int i = 0; i<n; i++) {
        printf("Please enter a value: ");
        scanf("%i", &input[i]);
        insert_node(root, create_node(input[i]));
    }

    //print bst in order
    printf("\nBST in order:\n");
    print_bst_InOrder(root);

    int m;
    printf("\n\nPlease enter the value you want to search for: ");
    scanf("%i", &m);
    search_node(root, m);

    int d;
    printf("\n\nPlease enter value you want to delete: ");
    scanf("%i",&d);
    delete_node(root, d);
    print_bst_InOrder(root);

    free_bst(root);

}

//creates BST node
node* create_node(int input) {
    node* temp = malloc(sizeof(node));
    temp->val = input;
    temp->left=NULL;
    temp->right=NULL;
    
    return temp;
}

//function for insertion of node
node* insert_node(node* root, node* temp) {
    
    if (NULL==root) {return temp;} 
    else if (temp->val>root->val) {
        insert_node(root->right, temp);
        if(!root->right) {root->right=temp;}
    } 
    else if (temp->val<root->val) {
        insert_node(root->left, temp);
        if(!root->left) {root->left=temp;}
    } 
    else if (temp->val==root->val) {
        printf("Input already exists in binary tree\n"); 
    }
    return root;
}

//function to print bst in order
void print_bst_InOrder(node* root) {

    if(!root) {return;}
        print_bst_InOrder(root->left);
        printf("%i ", root->val);
        print_bst_InOrder(root->right);
}

//function for searching for a particular value in the BST  
void search_node(node* root, int input) {
    if(!root) {printf("%i is not present in the BST", input);}
    else if(input == root->val) {printf("\n%i is present in the BST", input);}
    else if(input>root->val) {search_node(root->right, input);}
    else if(input<root->val) {search_node(root->left, input);}
}

//function to delete a node
void delete_node(node* root, int input) {
    node* temp = NULL;
    node* reinsert = NULL;
    if(!root) {printf("\n%i is not present in the BST\n", input);}
    else if(input == root->right->val) {
        temp = root->right;
        root->right = root->right->right;
        reinsert = temp->left;
        free(temp);
        if (reinsert) {root = insert_node(root, reinsert);}
        printf("%i has been deleted!\n", input);
    } else if(input == root->left->val) {
        temp = root->left;
        root->left = root->left->left;
        reinsert = temp->right;
        free(temp);
        if (reinsert) {root = insert_node(root, reinsert);}
        printf("%i has been deleted!\n", input);
    } else if (input>root->val) {delete_node(root->right, input);}
    else if (input<root->val) {delete_node(root->left, input);} 
    else {printf("%i is not present in BST", input);}
    
}
//function to free all nodes in a bst 
void free_bst(node* root) {
    if (!root) {
        free_bst(root->right);
        free_bst(root->left);
        free(root);
    }
}
