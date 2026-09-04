#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customLib.h"

// protypes
void isPhone(node *temp);
void isAddress(node *temp);
void isEmail(node *temp);
void saveInfo(node *temp);



// ADD CONTACT

int addContact(void) {
    printf("ENTER INFORMATION.\n");
    char name[100];
    while (1) {
        printf("Name: ");
        if (scanf("%99s", name) != 1) {
            printf("Try again!\n");
            continue;
        }

        int len = strlen(name);
        bool isAlpha = true;
        for (int i = 0; i < len; i++) {
            if (!isalpha(name[i])) {
                printf("Alphabetical only!\n");
                isAlpha = false;
                break;
            }
        }

        if (!isAlpha) {
            continue;
        }

        // malloc 
        node *temp = malloc(sizeof(node));

        // get first character
        char firstChar = tolower(name[0]);
        int index = (firstChar - 'a') % SIZE;

        strcpy(temp->name, name);



        // call isPhone function
        isPhone(temp);

        // call isAddress function
        isAddress(temp);

        // call isEmail function
        isEmail(temp);

        // save info to file .txt
        saveInfo(temp);

        // next node or address
        temp->next = tables[index];

        tables[index] = temp;


        return 1;

    }
}

// add contact helper function

void isPhone(node *temp) {
    char phone[100];
    while (1) {
        printf("Phone: ");
        if (scanf("%99s", phone) != 1) {
            printf("Try again!\n");
            continue;
        }

        int len = strlen(phone);
        bool isDigit = true;
        for (int i = 0; i < len; i++) {
            if (!isdigit(phone[i])) {
                printf("Digits only!\n");
                isDigit = false;
                break;
            }
        }

        if (!isDigit) {
            continue;
        }

        strcpy(temp->phone, phone);

        return;
    }
}

void isAddress(node *temp) {
    char address[100];
    while (1) {
        printf("address: ");
        if (scanf("%99s", address) != 1) {
            printf("Try again!\n");
            continue;
        }

        strcpy(temp->address, address);

        return;
    }
}

void isEmail(node *temp) {
    char email[100];
    while (1) {
        printf("Email: ");
        if (scanf("%99s", email) != 1) {
            printf("Try again!\n");
            continue;
        }

        int len = strlen(email);
        int atSign = 0;
        for (int i = 5; i < len; i++) {
            if (email[i] == '@') {
                atSign++;
            }
        }

        if (atSign != 1) {
            printf("Missing or multiple '@' \n");
            continue;
        }

        strcpy(temp->email, email);
        
        return;
    }
}


// save info to file .txt
void saveInfo(node *temp) {

    FILE *file = fopen("credentials.txt", "a");
    if (file == NULL) {
        printf("fopen failed!\n");
        return;
    } 

    fprintf(file, "%s|%s|%s|%s\n", temp->name, temp->phone, temp->address, temp->email);

    return;
}






























// view all contact

//search for a contact
    // search by name
    // or phone

// view a single contact

// edit a contact

// delete a contact

// save contacts to a file

// load contacts from the file when the program starts

// sort contacts
    // alphabetically 

// count total contacts

// exit the program safely