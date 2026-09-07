#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


int main(void) {

    // load data to memory
    loadFiles();

    // printFile();

    while (1) {

        // choose mode
        int mode = -1;
        printf("\033[33mCHOOSE A MODE\033[0m\n");
        printf("\033[36m[0] - Exit\033[0m\n");
        printf("\033[32m[1] - Add Contact\033[0m\n");
        printf("\033[32m[2] - Search Contact\033[0m\n");
        printf("\033[32m[3] - Edit Contact\033[0m\n");
        printf("\033[1;31m[4] - Delete Contact\033[0m\n");
        printf("::: ");
        if (scanf("%i", &mode) != 1) {
            printf("\033[31mEnter a valid input!\033[0m\n");
            while (getchar() != '\n');
            continue;
        }


        // call function mode
        switch (mode) {
            case 0:
                // quit
                freeMem();
                printf("\033[1;31mBABYE!!!\033[0m\n");
                return 0;
            case 1:
                // add contact
                addContact();
                break;
            case 2:
                // search contact
                searchContact();
                break;
            case 3:
                // edit contact
                editContact();
                break;
            case 4:
                // delete contact
                deleteContact();
                break;
        }
    }

    //free memory
    freeMem();

    return 0;
}





    // printf("\033[31mRed text\033[0m\n");
    // printf("\033[32mGreen text\033[0m\n");
    // printf("\033[33mYellow text\033[0m\n");
    // printf("\033[34mBlue text\033[0m\n");
    // printf("\033[35mMagenta text\033[0m\n");
    // printf("\033[36mCyan text\033[0m\n");

    // // bold/bright variants
    // printf("\033[1;31mBold red\033[0m\n");
    // printf("\033[1;32mBold green\033[0m\n");



