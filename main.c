#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Arrays/arrays.h"

int main() {
    char description [] = ".... Data Structures .....";
    printCharArray(description);

    int intArray [] = {1020304050};
    int intArraySize = sizeof(intArray) / sizeof(int);
    printIntArray(intArray, intArraySize);

    int Matrix[2][4] = {{1,2,3,4},{5,6,7,8}};
    print2DArray(2, 4, Matrix);

    getch();
    return 0;
}
