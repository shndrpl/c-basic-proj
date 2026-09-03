#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customLib.h"


int isName(void);



// ADD CONTACT
void addContact(void) {
    
    while (1) {
        do {
            if (isName() == 1) {
                break;
            }
        }
        while (1);

        





        
    }
    
}

// add contact helper function

int isName(void) {
    char name[50];
    int attemps = 0;
    while (1) {
        printf("Enter Name: ");
        if (scanf("%49s", name) != 1) {
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
            attemps++;
            continue;
        }

        // malloc 
        node *temp = malloc(sizeof(node));

        // get first character
        char firstChar = tolower(name[0]);
        int index = (firstChar - 'a') % SIZE;

        strcpy(temp->name, name);

        printf("%c, %i\n", firstChar, index);
        return 1;

    }
}

// bool isPhone(void) {}

// bool isAddress(void) {}

// bool isEmail(void) {}






























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