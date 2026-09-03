#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


node *tables[SIZE] = {NULL};

void loadFiles(void);
void printFile(void);




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

            printf("%s %i\n", temp->name, index);

            temp->next = tables[index];

            tables[index] = temp;

        }
        else {
            return;
        }

    }
}


void printFile(void) {
    for (int i = 0; i < SIZE; i++) {
        for (node *ptr = tables[i]; ptr != NULL; ptr = ptr->next) {
            printf("Name: %s | Phone: %s | Address: %s | Email: %s\n", ptr->name, ptr->phone, ptr->address, ptr->email);
        }
    }
    return;
}


