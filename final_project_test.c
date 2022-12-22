#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX 26

typedef struct TrieNode {
    int LeafNode; //1 if it is a leaf node, non-zero if it is not
    struct TrieNode* character[MAX];
    char* phone_number;
} TrieNode;

char word[20];
int pos=0;

TrieNode* create_node();
void insert_TrieNode(TrieNode* root, char* input, char* number);
TrieNode* search_TrieNode(TrieNode* root, char* input);
void update(TrieNode* root, char* input, char* number);
int delete_TrieNode(TrieNode** root, char* input);
void print_trie(TrieNode* root, char* word, int pos);
void free_Trie(TrieNode* root);
bool children(TrieNode* node);

int main() {

    TrieNode* root = create_node();
    TrieNode* root1 = NULL;

    //arrays of test cases
    char* test_contact[] = {"Aarushi", "Ashwin", "shreya", "riyo", "RiyOsha", "Yash", "M J", "Riyo"};
    char* test_numbers[] = {"7757959758", "1000860009", "9899765445", "9850274658", "9784027562", "9684067483", "5975345609", "9850285768"};

    printf("Test cases of different names and numbers in sentence case: \n");
    //inserts test contacts
    for (int i = 0; i<sizeof(test_contact)/sizeof(char*); i++) {
        insert_TrieNode(root, test_contact[i], test_numbers[i]);
    }

    //searches for test contact numbers
    for (int i = 0; i<sizeof(test_contact)/sizeof(char*); i++) {
        if(search_TrieNode(root, test_contact[i])!=NULL) {
            printf("%s's phone number is %s\n", test_contact[i], search_TrieNode(root, test_contact[i])->phone_number);
        }
    }

    //when root1 = NULL
    printf("\nTest case when trie is empty: \n");
    insert_TrieNode(root1, test_contact[1], test_numbers[1]);
    search_TrieNode(root1, test_contact[1]);
    delete_TrieNode(&root1, test_contact[3]);
    print_trie(root1, word, 0);

    //test case to search a name not in phone book
    printf("\n\nTest case to search for a name not in the Phonebook: \n");
    search_TrieNode(root, "ishita");

    //test cases for update
    printf("\nTest cases for update function: \n");
    update(root, test_contact[2], "989039848");
    update(root, "Rahul", "989039848");

    // deletion test cases
    printf("\nTest cases for deletion: \n");
    delete_TrieNode(&root, "yolo");//doesn't do anything when name not in phonebook is entered
    delete_TrieNode(&root, test_contact[3]);//deletes name successfuly
    delete_TrieNode(&root, "Riyo");
    delete_TrieNode(&root, "M J");
    search_TrieNode(root, test_contact[3]);
    search_TrieNode(root, "riyo");//prefix name deleted successfully 
    printf("%s", search_TrieNode(root, "Riyosha")->phone_number);//larger name still remains intact

    //print entire phonebook
    printf("\n\nPhonebook: \n");
    print_trie(root, word, pos);

    free_Trie(root);

}

//creates a node that points to NULL aray 
TrieNode* create_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->LeafNode=0;
    for (int i=0;i<MAX;i++) {
        node->character[i] = NULL;
    }
    node->phone_number="0";
    return node;
}

//insert a new contact 
void insert_TrieNode(TrieNode* root, char* input, char* number) {

    //root==NULL
    if (!root) {
        printf("Phonebook is empty\n");
        return;
    }

    TrieNode* temp = root;

    for (int i=0; i<strlen(input);i++) {

        if ((65>input[i]||input[i]>90)&&(input[i]<97||input[i]>122)) {
            printf("Please only use alphabets. Contact not added.\n");
            return;
        }

        //check if a node pointing to the character position exists
        //if it doesn't, create one 
        if (!temp->character[tolower(input[i])-'a']) {
            temp->character[tolower(input[i])-'a']=create_node();
        }
        //if it does, move on to next letter in the string
        temp=temp->character[tolower(input[i])-'a'];
    } 
    //make the last letter the leaf node
    if (temp->LeafNode==1) {
        printf("%s already exists in phonebook. You can try to use update instead\n", input);
        return;
    } else {
        temp->LeafNode=1;
        temp->phone_number=number;
        printf("Successfully added!\n");
        return;
    }
    
}

//search for a person's number
TrieNode* search_TrieNode(TrieNode* root, char* input) {

    //if root == NULL, return empty
    if (root==NULL) {
        printf("Phonebook is empty\n");
        return NULL;
    }

    TrieNode* temp = root;

    //iterate through the characters of the input
    for(int i =0;i<strlen(input);i++) {
        
        if ((65>input[i]||input[i]>90)&&(input[i]<97||input[i]>122)) {
            printf("Please only use alphabets. Cannot search for %s.\n", input);
            return NULL;
        }
        temp=temp->character[tolower(input[i]) -'a'];
        //if temp == NULL, input isn't present in trie
        if(!temp) {
            printf("Contact not found\n");
            return NULL;
        }
    }
    //if end of loop reached with leaf node = 0, name isn't in phonebook
    if (temp->LeafNode!=1) {
        printf("Contact not found\n");
        return NULL;
    } else {
        return temp;
    }
}


//update contact number
void update(TrieNode* root, char* input, char* number) {
    
    //root==NULL
    if (!root) {
        printf("Phonebook is empty");
        return;
    }

    TrieNode* node = search_TrieNode(root, input);
    if(!node) {//no update to be made
        return;
    }
    node->phone_number=number;
    printf("%s's number has been updated to %s\n", input, number);
    return;
}

//functions checks whether node has any children
//ie whether that particular letter is followed by other letters in any other names
bool children(TrieNode* node) {
    int flag=0;
    for(int i=0;i<MAX;i++) {
        if(node->character[i]) {
            flag=1;
        }
    }
    if (flag) {return true;}
    else {return false;}
}

//delete a contact 
int delete_TrieNode(TrieNode** root, char* input) {

    //check if trie exists
    if(!*root) {
        printf("Phonebook is empty\n");
    }

    //if yes, recursively reach the leaf node and check whether it has children or not
    //ie, whther it can be deleted or not 
    for (int i=0;i<strlen(input);i++) {
        
        if ((65>input[i]||input[i]>90)&&(input[i]<97||input[i]>122)) {
            return 2;
        }

        if(*root && (*root)->character[tolower(input[i])-'a'] && delete_TrieNode(&((*root)->character[tolower(input[i])-'a']), input+1)==1 && (*root)->LeafNode==0) {
            if(children(*root)) {
                return 0;
            } else {
                free(*root);
                *root=NULL;
                return 1;//frees node if no children present
            }
        }
    }

    //leaf node case
    if(*input=='\0'&&(*root)->LeafNode==1) {
        if(!children(*root)) {
            free(*root);
            *root=NULL;
            return 1; //tells function to check its parent node in a similar manner
        } else {
            (*root)->LeafNode=0;
            return 0;//tells function to not check parent node, and just changes leaf node status
        }
    }
    return 0;
}

//print all names with their numbers 
void print_trie(TrieNode* root, char* word, int pos) {
    //empty trie case
    if (!root) {
        printf("Phonebook is empty");
        return;
    }
    //base case when leaf node is reached
    //print word array
    if(root->LeafNode){
        word[pos]='\0';//string end
        for(int j=0; j<pos+1;j++) {
            printf("%c", word[j]);
        }
        printf("  %s\n", root->phone_number);
    }
    //recursively keep adding the letters of a name to a word array till leaf node is reached 
    for (int i=0; i<MAX;i++) {
        if (root->character[i]){
            word[pos] = i+'a';
            print_trie(root->character[i], word, pos+1);
        }
    }
}


//free trie
void free_Trie(TrieNode* root)
{
    if(!root) {
        return;
    }

    //recursively go to the end of the trie
    for (int i = 0; i < MAX; i++) {
       free_Trie(root->character[i]);
    }

    //base case
    free(root);
}