#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


int main(void) {

    // load data to memory
    loadFiles();

    while (1) {

        // choose mode
        int mode = -1;
        printf("CHOOSE MODE.\n");
        printf("[0] - Quit\n");
        printf("[1] - Add Contact\n");
        printf("[2] - Search Contact\n");
        printf("[3] - View Single Contact\n");
        printf("[4] - Delete Contact\n");
        printf("::: ");
        if (scanf("%i", &mode) != 1) {
            printf("Enter a valid input!\n");
            while (getchar() != '\n');
            continue;
        }



        // call function mode
        switch (mode) {
            case 0:
                // quit
                freeMem();
                return 0;
            case 1:
                // add contact
                addContact();
                break;
            case 2:
                // search contact
                searchContact();
                break;
        }

        //free memory
        freeMem();

        return 0;
    }

}



