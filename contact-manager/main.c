#include <stdio.h>
#include <stdlib.h>
#include "customLib.h"


int main(void) {
    node *temp = malloc(sizeof(node));

    loadFiles(temp);

    // printFile(temp);

    return 0;
}