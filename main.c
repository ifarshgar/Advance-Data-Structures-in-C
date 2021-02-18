#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Arrays/arrays.h"
#include "Binary Search/Binary_Search.h"
#include "Sequential Search/Sequential_Search.h"

void test_array_lib();

#define SIZE 1000000000   // One Billion
#define TOFIND 200000000  // Two hundred million
int *data;

void test_helper();
void test_sequential_search_library();
void test_binary_search_library();

int main() {
    printf(".... Data Structures .....\n\n");
    test_array_lib();

    test_helper();
    test_sequential_search_library();
    test_binary_search_library();

    free(data);
    getch();
    return 0;
}

void test_array_lib() {
    char description[] = ".... Test Array Library .....";
    printCharArray(description);

    int intArray[] = {1020304050};
    int intArraySize = sizeof(intArray) / sizeof(int);
    printIntArray(intArray, intArraySize);

    int Matrix[2][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8}};
    print2DArray(2, 4, Matrix);
}

void test_helper() {
    printf("\nPlease wait...");
    clock_t start, end;
    start = clock();

    // Dynamic memory allocation
    data = (int *) malloc(sizeof(int) * SIZE);
    // populating the data array with random numbers
    for (int i = 0; i < SIZE; i++)
        data[i] = i;

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime spent for initialization: %f\n", elapsed);
}

void test_sequential_search_library() {
    printf(".... Test Search Libraries .....\n");
    clock_t start, end;
    start = clock();
    int result = sequential_search(TOFIND, data, SIZE);
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sequential search: %f\n", elapsed);
}

void test_binary_search_library() {
    printf(".... Test Search Libraries .....\n");
    clock_t start, end;
    start = clock();
    int result = binary_search(TOFIND, data, SIZE);
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Binary search: %f\n", elapsed);
}