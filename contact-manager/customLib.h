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
void loadFiles(void);
void printFile(void);
void freeMem(void);

// tables or buckets
extern node *tables[SIZE];

// function declarations
int addContact(void);
void searchContact(void);
void editContact(void);
void deleteContact(void);



// void loadContactsFromFile();
// void sortContacts();
// void exitProgram();

#endif