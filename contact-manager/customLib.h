#ifndef customLib_h
#define customLib_h

#define SIZE 26

// node struct
typedef struct node {
    char name[100];
    char phone[100];
    char address[100];
    char email[100];
    struct node *next;
} node;

// file IO
void loadFiles(node *temp);
void printFile(node *temp);

// tables or buckets
extern node *tables[SIZE];

// function declarations
void addContact(node *temp);
// void searchContact();
// void viewSingleContact();
// void editContact();
// void deleteContact();
// void loadContactsFromFile();
// void sortContacts();
// void exitProgram();

#endif