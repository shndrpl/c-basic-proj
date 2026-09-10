#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customLib.h"
#include <stdbool.h>

// protypes
void isPhone(node *temp);
void isAddress(node *temp);
void isEmail(node *temp);
void saveInfo(node *temp);

char *nameValidation(void);
char *phoneValidation(void);
char *addressValidation(void);
char *emailValidation(void);



// ADD CONTACT

int addContact(void) {
    printf("\033[1;32mENTER INFORMATION\033[0m\n");
    
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
        char firstChar = name[0];
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
    char *tempPhone = phoneValidation();

    // copy 
    char phone[100];
    strcpy(phone, tempPhone);

    // free
    free(tempPhone);

    strcpy(temp->phone, phone);

    return;
}

void isAddress(node *temp) {
    char *tempAddress = addressValidation();

    // copy
    char address[100];
    strcpy(address, tempAddress);

    // free
    free(tempAddress);

    strcpy(temp->address, address);

    return;
}

void isEmail(node *temp) {
    char *tempEmail = emailValidation();

    // copy
    char email[100];
    strcpy(email, tempEmail);

    // free
    free(tempEmail);

    strcpy(temp->email, email);

    return;
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
    printf("\033[1;32mSEARCH A CONTACT\033[0m\n");

    char *tempName = nameValidation();

    // copy the name from tempName
    char name[100];
    strcpy(name, tempName);

    // free tempName
    free(tempName);

    // get index of firstChar
    char firstChar = name[0];
    int index = ((unsigned char)firstChar - 'a') % SIZE;

    bool isMatch = false;

    for (node *ptr = tables[index]; ptr != NULL; ptr = ptr->next) {

        int len = strlen(ptr->name);

        for (int i = 0; i < len; i++) {
            ptr->name[i] = tolower(ptr->name[i]);
        }

        if (strcmp(ptr->name, name) == 0) {
            isMatch = true;
            printf("\033[35mFOUND!\033[0m\n");
            printf("\033[35mName: %s | Phone: %s | Address: %s | Email: %s\033[0m\n", ptr->name, ptr->phone, ptr->address, ptr->email);

            printf("\n");
        }
    }

    if (!isMatch) {
        printf("\033[31mNo Match!\033[0m\n");
        printf("\n");
    }
}


// nameValidation() | helper function for addContact and searchContact
char *nameValidation(void) {
    // ask name to search
    char *name = malloc(sizeof(char) * 100);
    while (1) {
        printf("\033[33mName: \033[0m");

        if (scanf(" %99[^\n]", name) != 1) {
            printf("\033[Please enter a valid name!\033[0m\n");

            continue;
        }

        int len = strlen(name);

        for (int i = 0; i < len; i++) {
            name[i] = tolower(name[i]);
        }

        bool isAlpha = true;
        for (int i = 0; i < len; i++) {
            if (!isalpha((unsigned char)name[i]) && name[i] != ' ') {
                printf("\033[31mAlphabetical Only!\033[0m\n");
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
    printf("\033[1;32mDELETE A CONTACT\033[0m\n");

    char *tempName = nameValidation();

    // copy
    char name[100];
    strcpy(name, tempName);

    // free
    free(tempName);

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
            printf("\033[35mDeleted Successfully.\033[0m\n");
            printf("\n");
        }

    }

    fclose(file);
    fclose(tempFile);

    remove("credentials.txt");
    rename("temp.txt", "credentials.txt");

    freeMem();
    loadFiles();

    return;
}




// phone validation
char *phoneValidation(void) {
    char *phone = malloc(sizeof(char) * 100);
    while (1) {
        while (getchar() != '\n');
        printf("\033[33mPhone: \033[0m");

        if (scanf("%99s", phone) != 1) {
            printf("Try again!\n");
            continue;
        }

        int len = strlen(phone);
    
        if (len < 10) {
            printf("Phone number must be 10 digit more.\n");
            continue;
        }

        bool isDigit = true;
        for (int i = 0; i < len; i++) {
            if (!isdigit(phone[i])) {
                printf("\033[31mDigits Only!\033[0m\n");
                isDigit = false;
                break;
            }
        }

        if (!isDigit) {
            continue;
        }
        else {
            return phone;
        }
    }
}


// address validation
char *addressValidation(void) {
    char *address = malloc(sizeof(char) * 100);
    while (1) {
        printf("\033[33mAddress: \033[0m");
        if (scanf("%99s", address) != 1) {
            printf("Try again!\n");
            continue;
        }

        return address;
    }
}

// email validation
char *emailValidation(void) {
    char *email = malloc(sizeof(char) * 100);
    while (1) {
        while (getchar() != '\n');
        printf("\033[33mEmail: \033[0m");

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
             printf("\033[31mMissing or multiple '@'\033[0m\n");
            continue;
        }
        
        return email;
    }
}




// edit contact
 void editContact(void) {
    printf("\033[1;32mEDIT CONTACT\033[0m\n");

    char *tempName = nameValidation();

    // copy
    char name[100];
    strcpy(name, tempName);

    // free
    free(tempName);

    // open file .txt
    FILE *file = fopen("credentials.txt", "r");
    FILE *tempFile = fopen("temp.txt", "a");

    if (file == NULL || tempFile == NULL) {
        printf("fopen Failed!\n");
        return;
    }

    char line[400];
    bool isMatch = false;

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
            printf("\033[32mENTER NEW INFORMATION\033[0m\n");
            
            int index = (name[0] - 'a') % SIZE;

            for (node *ptr = tables[index]; ptr != NULL; ptr = ptr->next) {
                int ptrNameLen = strlen(ptr->name);

                // convert to lower case
                for (int i = 0; i < ptrNameLen; i++) {
                    ptr->name[i] = tolower(ptr->name[i]);
                }

                if (strcmp(ptr->name, name) == 0) {
                    isMatch = true;
                    // ASK NEW NAME
                    char *secondTempName = nameValidation();

                    // copy
                    char secondName[100];
                    strcpy(secondName, secondTempName);

                    // free
                    free(secondTempName);



                    // ASK NEW PHONE
                    char *tempPhone = phoneValidation();

                    // copy
                    char phone[100];
                    strcpy(phone, tempPhone);

                    // free
                    free(tempPhone);



                    // ASK NEW ADDRESS
                    char *tempAddress = addressValidation();

                    // copy
                    char address[100];
                    strcpy(address, tempAddress);

                    // free
                    free(tempAddress);


                    // ASK NEW EMAIL
                    char *tempEmail = emailValidation();

                    // copy
                    char email[100];
                    strcpy(email, tempEmail);

                    // free
                    free(tempEmail);


                    char buffer[405];
                    sprintf(buffer, "%s|%s|%s|%s\n", secondName, phone, address, email);

                    fputs(buffer, tempFile);
                    printf("\033[35mEdited successfully\033[0m\n");
                    printf("\n");

                }
            }
        }

    }

    if (!isMatch) {
        printf("\033[31mNo Match!\033[0m\n");
    }

    fclose(file);
    fclose(tempFile);

    remove("credentials.txt");
    rename("temp.txt", "credentials.txt");

    freeMem();
    loadFiles();

    return;
 }



