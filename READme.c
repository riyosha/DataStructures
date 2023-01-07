/*
This repository contains all the data structures I coded up during my Data Structures course.
*/


/*
The final project implements a phonebook using tries.
Each Trie Node stores:
    - int LeafNode - gives information about reaching end of the word
    - an array of 26 pointers to Trie Nodes
    - a phone number string

Using this trie phonebook, we can insert contact names and their phone numbers.
    - The trie doesn't allow duplicate names
    - However, prefixes of names can be stored. Both 'Raj' and 'Rajat' can be stored.
    - Names are case insensitive
    - Names can't have special characters and numbers (including space)

Operations supported - 
    - We can insert contact names with their numbers.
    - We can delete contact names
    - We can update a contact's phone number 
    - We can search for a contact name's phone number
    - we can print the entire phonebook 
        - currently, this function can't print out names and numbers of prefix names.
        for example, riyosha and her number will be printed, but riyo's number will not be printed
        I have not found a way to fix that yet, but will find one soon.

Test cases -
    - Test cases insert sentence case names, names with special characters, duplicate names
    - Search names that are present and not present in phone book
    - Delete names and prefix names present in phonebook. does not do anything is special characters involved/name not present in phonebook
    - update names present, shows error for names not present
    - prints phonebook
    - tests all functions in case of empty trie
    - frees the tree in the end

    - for additional testing, names and numbers can simply be added to the test_contacts and test_numbers arrays.

how to run - 
simply compile the code and run it. all additional test cases will have to be hard coded in the code itself.

1st command line prompt - 
gcc -g3 -Wall -o final_project_test final_project_test.c
2nd command line prompt - 
./final_project_test


*/
