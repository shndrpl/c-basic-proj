#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


node *tables[SIZE] = {NULL};


// copy data from file to memory
void loadFiles(void) {
    FILE *file = fopen("credentials.txt", "r");
    if (file == NULL) {
        printf("fopen failed!\n");
        return;
    }

    while (1) {
        // malloc
        node *temp = malloc(sizeof(node)); 

        if (fscanf(file, "%99[^|]|%99[^|]|%99[^|]|%99[^\n]\n", temp->name, temp->phone, temp->address, temp->email) == 4) {

            // get index
            char firstChar = tolower((unsigned char)temp->name[0]);
            int index = (firstChar - 'a') % SIZE;

            temp->next = tables[index];

            tables[index] = temp;

        }
        else {
            free(temp);
            fclose(file);
            return;
        }

    }
}

// print data
void printFile(void) {
    for (int i = 0; i < SIZE; i++) {
        for (node *ptr = tables[i]; ptr != NULL; ptr = ptr->next) {
            printf("Name: %s | Phone: %s | Address: %s | Email: %s\n", ptr->name, ptr->phone, ptr->address, ptr->email);
        }
    }
    return;
}


// free memory
void freeMem(void) {
    for (int i = 0; i < SIZE; i++) {
        node *temp = tables[i];

        while (temp != NULL) {
            node *n = temp;
            temp = temp->next;
            free(n);
        }

        tables[i] = NULL;
    }

    return;
}

