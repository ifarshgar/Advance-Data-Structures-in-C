#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Arrays/arrays.h"
#include "Binary Search/Binary_Search.h"
#include "Sequential Search/Sequential_Search.h"
#include "Queue/Queue.h"

#define SIZE 10000000   // Ten Million
#define TO_FIND 6715234 // a random number
int *data;

void test_helper();
void test_array_lib();
void test_sequential_search_library();
void test_binary_search_library();
void test_queue_library();

int main() {
    printf(".... Data Structures .....\n\n");
    test_array_lib();

    test_helper();
    test_sequential_search_library();
    test_binary_search_library();
    test_queue_library();

    free(data);
    return 0;
}

void test_array_lib() {
    char description[] = "\n.... Test Array Library .....";
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
    printf("\nTime spent for initialization: %f s\n", elapsed);
}

void test_sequential_search_library() {
    printf("\n.... Test Search Libraries .....\n");
    clock_t start, end;
    start = clock();
    int result = sequential_search(TO_FIND, data, SIZE);
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sequential search: %f s\n", elapsed);
}

void test_binary_search_library() {
    printf("\n.... Test Search Libraries .....\n");
    clock_t start, end;
    start = clock();
    int result = binary_search(TO_FIND, data, SIZE);
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Binary search: %f s\n", elapsed);
}

void test_queue_library() {
    printf("\n.... Test Queue Library .....\n");
    clock_t start, end;
    start = clock();
    for(int i=0; i<100; i++) {
        queue_push(i);
    }
    for(int i=0; i<90; i++) {
        queue_pop();
    }
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Queue operations: %f s\n", elapsed);
    printf("Queue size: %d\n", queue_size());
    queue_print();
}