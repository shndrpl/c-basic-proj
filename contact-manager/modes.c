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

char *nameValidation(void);



// ADD CONTACT

int addContact(void) {
    printf("ENTER INFORMATION.\n");
    while (1) {
        char *tempName = nameValidation();

        // copy name from tempName pointer var
        char name[100];
        strcpy(name, tempName);

        // free tempName
        free(tempName);

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
        while (getchar() != '\n');
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
        while (getchar() != '\n');
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


// save info to file .txt | helper function for addContact()
void saveInfo(node *temp) {

    FILE *file = fopen("credentials.txt", "a");
    if (file == NULL) {
        printf("fopen failed!\n");
        return;
    } 

    fprintf(file, "%s|%s|%s|%s\n", temp->name, temp->phone, temp->address, temp->email);

    fclose(file);

    return;
}



// search contact function
void searchContact(void) {

    char *tempName = nameValidation();

    // copy the name from tempName
    char name[100];
    strcpy(name, tempName);

    // free tempName
    free(tempName);

    // get index of firstChar
    char firstChar = name[0];
    int index = ((unsigned char)firstChar - 'a') % SIZE;

    for (node *ptr = tables[index]; ptr != NULL; ptr = ptr->next) {

        int len = strlen(ptr->name);

        for (int i = 0; i < len; i++) {
            ptr->name[i] = tolower(ptr->name[i]);
        }

        if (strcmp(ptr->name, name) == 0) {
            printf("FOUND!\n");
            printf("Name: %s | Phone: %s | Address: %s | Email: %s \n", ptr->name, ptr->phone, ptr->address, ptr->email);
            return;
        }
        else {
            printf("NO MATCH!\n");
            printf("Complete name only.\n");
            return;
        }
    }
}


// nameValidation() | helper function for addContact and searchContact
char *nameValidation(void) {
    // ask name to search
    char *name = malloc(sizeof(char) * 100);
    while (1) {
        printf("Name: ");
        if (scanf(" %99[^\n]", name) != 1) {
            printf("Please enter a valid name!\n");
            continue;
        }

        int len = strlen(name);

        for (int i = 0; i < len; i++) {
            name[i] = tolower(name[i]);
        }

        bool isAlpha = true;
        for (int i = 0; i < len; i++) {
            if (!isalpha((unsigned char)name[i]) && name[i] != ' ') {
                printf("Alphabetical only!\n");
                isAlpha = false;
                break;
            }
        }

        if (isAlpha) {
            return name;
        }
    }
}




// delete contact function
void deleteContact(void) {

    char *name = nameValidation();
    
    // get index of firstChar
    char firstChar = name[0];
    int index = ((unsigned char)firstChar - 'a') % SIZE;

    // open file .txt
    FILE *file = fopen("credentials.txt", "r");
    FILE *tempFile = fopen("temp.txt", "a");

    if (file == NULL || tempFile == NULL) {
        printf("fopen Failed!\n");
        return;
    }

    char line[400];

    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);

        for (int i = 0; i < len; i++) {
            line[i] = tolower(line[i]);
        }

        // get len of name
        int nameLen = strlen(name);
        char tempName[100];

        for (int j = 0; j < nameLen; j++) {
            tempName[j] = line[j];
        }
        tempName[nameLen] = '\0';

        if (strcmp(tempName, name) != 0) {
            fputs(line, tempFile);
        }
        else {
            printf("Found... Deleted!\n");
        }

    }

    fclose(file);
    fclose(tempFile);

    remove("credentials.txt");
    rename("temp.txt", "credentials.txt");

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