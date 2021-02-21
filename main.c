#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arrays/arrays.h"
#include "Binary Search/Binary_Search.h"
#include "Sequential Search/Sequential_Search.h"
#include "Simple Queue/SimpleQueue.h"
#include "Generic Queue/Queue.h"
#include "Binary Tree/BinaryTree.h"

#define SIZE 100000000   // 100 Million
#define TO_FIND 63715234 // a random number around 60 Million
int *data;

void test_helper();
void test_array_lib();
void test_sequential_search_library();
void test_binary_search_library();
void test_simple_queue_library();
void test_generic_queue_library();
void test_binary_tree_library();

int main() {
    printf(".... Data Structures .....\n\n");

    test_array_lib();
    test_helper();
    test_sequential_search_library();
    test_binary_search_library();
    test_simple_queue_library();
    test_generic_queue_library();
    test_binary_tree_library();

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
    printf("Please wait...");
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

void test_simple_queue_library() {
    printf("\n.... Test Simple Queue Library .....\n");
    int count = 0;

    clock_t start, end;
    start = clock();
    for (int i = 0; i < 100; i++) {
        simple_queue_push(i);
        count++;
    }
    for (int i = 0; i < 90; i++) {
        simple_queue_pop();
        count--;
    }
    printf("Simple Queue size: %d - Count: %d\n", simple_queue_size(), count);
    simple_queue_print();

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSimple Queue operations: %f s\n", elapsed);
}

void test_generic_queue_library() {
    printf("\n.... Test Generic Queue Library .....\n");
    Queue *first = NULL;
    Queue *last = NULL;
    int count = 0;

    clock_t start, end;
    start = clock();
    for(int i=0; i<100; i++) {
        int *j = (int *)malloc(sizeof(int));
        *j = i;
        queue_push(j, &first, &last, _Integer);
        count++;
    }
    for(int i=0; i<90; i++) {
        queue_pop(&first, &last);
        count--;
    }
    printf("Generic Queue size: %d - Count: %d\n", queue_size(first), count);
    printf("\n- Generic Queue Type - Integer\n");
    queue_print(first, _Integer);


    Queue *first2 = NULL;
    Queue *last2 = NULL;
    BinaryTree *bt = _binary_tree_init();
    bt->data = 1;
    void *vvv = bt;
    queue_push(vvv, &first2, &last2, _BinaryTree);
    printf("\n- Generic Queue Type - BinaryTree\n");
    queue_print(first2, _BinaryTree);
    BinaryTree *bt2 = _binary_tree_init();
    bt2->data = 2;
    vvv = bt2;
    queue_push(vvv, &first2, &last2, _BinaryTree);
    printf("\n- Generic Queue Type - BinaryTree\n");
    queue_print(first2, _BinaryTree);

    Queue *first3 = NULL;
    Queue *last3 = NULL;
    char *i = "Element One";
    void *v = i;
    queue_push(v, &first3, &last3, _String);
    printf("\n- Generic Queue Type - String\n");
    queue_print(first3, _String);
    char *j = "Element Two";
    v = j;
    queue_push(v, &first3, &last3, _String);
    printf("\n- Generic Queue Type - String\n");
    queue_print(first3, _String);

    Queue *first4 = NULL;
    Queue *last4 = NULL;
    char *ii = "A";
    void *vv = ii;
    queue_push(vv, &first4, &last4, _Char);
    printf("\n- Generic Queue Type - Character\n");
    queue_print(first4, _Char);
    char *jj = "B";
    vv = jj;
    queue_push(vv, &first4, &last4, _Char);
    printf("\n- Generic Queue Type - Character\n");
    queue_print(first4, _Char);
    char *kk = "C";
    vv = kk;
    queue_push(vv, &first4, &last4, _Char);
    printf("\n- Generic Queue Type - Character\n");
    queue_print(first4, _Char);

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nGeneric Queue operations: %f s\n", elapsed);
}

void test_binary_tree_library() {
    printf("\n.... Test Binary Tree Library .....\n");

    clock_t start, end;
    start = clock();
    BinaryTree *root = NULL;

    binary_tree_insert(1, &root);
    binary_tree_insert(2, &root);
    binary_tree_insert(3, &root);
    binary_tree_insert(4, &root);
    binary_tree_insert(5, &root);
    binary_tree_insert(6, &root);
    binary_tree_insert(7, &root);

    printf("-Breadth First Search Traversal:\n");
    traverse(root, Breadth_First_Search);
    printf("-Pre-order Depth First Search Traversal:\n");
    traverse(root, Depth_First_Search_PreOrder);
    printf("-In-order Depth First Search Traversal:\n");
    traverse(root, Depth_First_Search_InOrder);
    printf("-Post-order Depth First Search Traversal:\n");
    traverse(root, Depth_First_Search_PostOrder);

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLinkList Queue operations: %f s\n", elapsed);
}