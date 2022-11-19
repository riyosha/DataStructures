#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    //struct TreeNode* parent;
    int height;
} TreeNode;

TreeNode* create_node (int input);
TreeNode* insert(TreeNode* root, TreeNode* new_node);
void print_avl_InOrder(TreeNode* root);
int difference(TreeNode* new_node);
int max(int a, int b);
TreeNode* right_rotate(TreeNode* node);
TreeNode* left_rotate(TreeNode* node);
void free_bst(TreeNode* root);
int height(TreeNode* root);

int main() {

    int n, value;
    TreeNode* root = NULL;

    //user input for value of root node
    printf("Please enter value of root node: ");
    scanf("%i", &value);
    root = insert(root, create_node(value));
    
    //user input for number of nodes desired 
    printf("How many nodes do you want to add? Enter a positive number: ");
    scanf("%i", &n);

    //asks for user input for new node n times
    //need to ensure that if user enters the same value twice, program asks for a value an extra time
    int input[n];
    for(int i = 0; i<n; i++) {
        printf("Please enter a value: ");
        scanf("%i", &input[i]);
        root = insert(root, create_node(input[i]));
    }

    //print avl in order
    printf("Original AVL is: ");
    print_avl_InOrder(root);

    free_bst(root);
}

TreeNode* create_node(int input) {
    TreeNode* temp = malloc(sizeof(TreeNode));
    temp->val = input;
    //temp->parent = NULL;
    temp->right = NULL;
    temp->left = NULL;
    temp->height = 1;
    return temp;
};

TreeNode* left_rotate(TreeNode* node) {
    TreeNode* y = node->right;
    
     
    node->right = y->left;
    y->left=node;
    //y->left->parent=node;
   
    //y->parent=node->parent; node->parent=y;
    
    node->height = max(height(node->left), height(node->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;

}

TreeNode* right_rotate(TreeNode* node) {
    TreeNode* y = node->left;
    
    //y->right->parent=node;
    node->left = y->right;
    y->right=node; 
    //y->parent=node->parent; node->parent=y;
    
    node->height = max(height(node->left), height(node->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}


TreeNode* insert(TreeNode* root, TreeNode* new_node) {
    if (new_node == NULL) return root;
    if (root==NULL) {return new_node;}
    if (new_node->val == root->val) {printf("Value already present in AVL"); return root;}
    else if (new_node->val>root->val) {root->right=insert(root->right, new_node);} 
    else if (new_node->val<root->val) {root->left=insert(root->left, new_node);}

    //update heights
    root->height = max(height(root->left), height(root->right))+1;

    //rotates
    //double left
    if (difference(root)>1&&new_node->val>root->right->val) {return left_rotate(root);}
    //right then left
    if (difference(root)>1&&new_node->val<root->right->val) {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    //double right
    if (difference(root)<-1&&new_node->val<root->left->val) {return right_rotate(root);}
    //left then right
    if (difference(root)<-1&&new_node->val>root->left->val) {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    return root;
}



int difference(TreeNode* node) {return height(node->right)-height(node->left);}

int max(int a, int b) {return (a > b) ? a : b;}

int height(TreeNode* root) {
    if(!root) return 0;
    return root->height;
}

void print_avl_InOrder(TreeNode* root) {
    if(!root) {return;}
    print_avl_InOrder(root->left);
    printf("%i ", root->val);
    print_avl_InOrder(root->right);
}

void free_bst(TreeNode* root) {
    if (!root) {
        free_bst(root->right);
        free_bst(root->left);
        free(root);
    }
}