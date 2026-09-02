#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


// ERROR: node *temp malloc should re execute every loop so it can create new memory address/
// to do that you need to intialized and declared it at the same file you implement the function.

// ERROR: put if statement for malloc and fopen if it failed

// ERROR: index can become negative int. Use unsigned int or other technique


node *tables[SIZE] = {NULL};


void loadFiles(node *temp) {

    FILE *file = fopen("credentials.txt", "r");

    while (fscanf(file, "%99[^|]|%99[^|]|%99[^|]|%99[^\n]", temp->name, temp->phone, temp->address, temp->email) == 4) {

        // get index
        char firstChar = tolower(temp->name[0]);
        int index = (firstChar - 'a') % SIZE;

        temp->next = tables[index];   

        tables[index] = temp;

    }

    return;
}


void printFile(node *temp) {
    for (node *ptr = temp; ptr != NULL; ptr = ptr->next) {
        printf("Name: %s | Phone: %s | Address: %s | Email: %s\n", ptr->name, ptr->phone, ptr->address, ptr->email);
    }
    return;
}


