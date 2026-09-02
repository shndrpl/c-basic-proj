#ifndef customLib_h
#define customLib_h

#define SIZE 26

// node struct
typedef struct node {
    char name[50];
    char phone[20];
    char address[50];
    char email[60];
    struct node *next;
} node;

// file IO
void loadFiles(node *temp);

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