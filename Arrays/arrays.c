#include <stdio.h>
#include "arrays.h"

void printCharArray(const char *s) {
    printf("%s\n", s);
}

void printIntArray(const int *num, int size) {
    for(int i=0; i<size; i++)
        printf("%d", num[i]);
    printf("\n");
}

void print2DArray(int row, int col, int m[row][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}