#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


int main(void) {

    // load data to memory
    loadFiles();

    // print data
    // printFile();

    // free memory
    // freeMem();

    while (1) {

        addContact();

        printFile();

        return 1;
    }
   

    return 0;
}



