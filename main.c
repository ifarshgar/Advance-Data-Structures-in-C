#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Arrays/arrays.h"
#include "Searching Algorithms/Binary Search/Binary_Search.h"
#include "Searching Algorithms/Sequential Search/Sequential_Search.h"
#include "Simple Queue/SimpleQueue.h"
#include "Simple Stack/SimpleStack.h"
#include "Generic Queue/Queue.h"
#include "Binary Tree/BinaryTree.h"
#include "Vector/Vector.h"

#define SIZE 100000000   // 100 Million
#define TO_FIND 63715234 // a random number around 60 Million
int *data;

void test_helper();
void test_array_lib();
void test_sequential_search_library();
void test_binary_search_library();
void test_simple_queue_library();
void test_simple_stack_library();
void test_generic_queue_library();
void test_binary_tree_library();

int main() {
    printf(".... Data Structures .....\n\n");

//    test_array_lib();
//    test_helper();
//    test_sequential_search_library();
//    test_binary_search_library();
//    test_simple_queue_library();
//    test_simple_stack_library();
    test_generic_queue_library();
//    test_binary_tree_library();

//    Vector *first = NULL;
//    Vector *last = NULL;
//
//    void *v = (void *) 10;
//    int res = vector_push(&first, &last, v);    // Insertion: method one
//    vector_push(&first, &last, (void*)20);   // Insertion: method two
//    vector_push(&first, &last, (void*)30);
//    vector_push(&first, &last, (void*)40);
//    vector_push(&first, &last, (void*)50);
//    if(res)
//        printf("Data inserted into the vector successfully!\n");
//
//    int size = vector_size(first);
//    printf("Vector size: %d\n", size);
//
//    int *r;
//    r = vector_get(first, last, 0);       // retrieving data: method 1
//    printf("Vector[0]: %d\n", *r);

//    int q = (int) vector_get(first, last, 1);   // retrieving data: method 2
//    printf("Vector[1] %d\n", q);
//    q = (int) vector_get(first, last, 2);
//    printf("Vector[2] %d\n", q);
//    q = (int) vector_get(first, last, 3);
//    printf("Vector[3] %d\n", q);
//    q = (int) vector_get(first, last, 4);
//    printf("Vector[4] %d\n", q);
//
//
//
//    q = (int) vector_pop(&first, &last);
//    printf("vector_pop(): %d\n", q);
//    q = (int) vector_pop(&first, &last);
//    printf("vector_pop(): %d\n", q);
//    q = (int) vector_pop(&first, &last);
//    printf("vector_pop(): %d\n", q);
//    q = (int) vector_pop(&first, &last);
//    printf("vector_pop(): %d\n", q);
//    q = (int) vector_pop(&first, &last);
//    printf("vector_pop(): %d\n", q);
//    q = (int) vector_pop(&first, &last);
//    printf("vector_pop(): %d\n", q);

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

void test_simple_stack_library() {
    printf("\n.... Test Simple Stack Library .....\n");
    int count = 0;

    clock_t start, end;
    start = clock();
    for (int i = 0; i < 100; i++) {
        simple_stack_push(i);
        count++;
    }
    for (int i = 0; i < 90; i++) {
        simple_stack_pop();
        count--;
    }
    printf("Simple Stack size: %d - Count: %d\n", simple_stack_size(), count);
    simple_stack_print();

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSimple Stack operations: %f s\n", elapsed);
}

void test_generic_queue_library() {
    printf("\n.... Test Generic Queue Library .....\n");

    Queue *first = NULL;
    Queue *last = NULL;

    // integer
    int *n = (int *) malloc(sizeof(int));
    *n = 1;
    queue_push(n, &first, &last);
    int *qi = queue_pop(&first, &last);
    printf("\n- Generic Queue Type - Integer - %d\n", *qi);

    // float
    float *f = (float *) malloc(sizeof(float));
    *f = 3.14f;
    queue_push(f, &first, &last);
    float *qf = queue_pop(&first, &last);
    printf("\n- Generic Queue Type - Float - %.2f\n", *qf);

    // char
    char *c = (char *) malloc(sizeof(char));
    *c = 'A';
    queue_push(c, &first, &last);
    char *qc = queue_pop(&first, &last);
    printf("\n- Generic Queue Type - Char - %c\n", *qc);

    // char
    char *s = (char *) malloc(20 * sizeof(char));
    strcpy(s, "Aley");
    queue_push(s, &first, &last);
    char *qs = queue_pop(&first, &last);
    printf("\n- Generic Queue Type - String - %s\n", qs);

    Queue *first2 = NULL;
    Queue *last2 = NULL;
    BinaryTree *bt = _binary_tree_init();
    bt->data = 1;
    void *vvv = bt;
    queue_push(vvv, &first2, &last2);
    printf("\n- Generic Queue Type - BinaryTree\n");
    queue_print(first2, _BinaryTree);
    BinaryTree *bt2 = _binary_tree_init();
    bt2->data = 2;
    vvv = bt2;
    queue_push(vvv, &first2, &last2);
    printf("- Generic Queue Type - BinaryTree\n");
    queue_print(first2, _BinaryTree);

    clock_t start, end;
    start = clock();
    int count = 0;
    for(int i=0; i<100; i++) {
        int *j = (int *)malloc(sizeof(int));
        *j = i;
        queue_push(j, &first, &last);
        count++;
    }
    for(int i=0; i<90; i++) {
        queue_pop(&first, &last);
        count--;
    }
    printf("\n- Generic Queue Type - Integer\n");
    queue_print(first, _Integer);
    printf("Generic Queue size: %d\n", queue_size(first));

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
    binary_tree_traverse(root, Breadth_First_Search);
    printf("-Pre-order Depth First Search Traversal:\n");
    binary_tree_traverse(root, Depth_First_Search_PreOrder);
    printf("-In-order Depth First Search Traversal:\n");
    binary_tree_traverse(root, Depth_First_Search_InOrder);
    printf("-Post-order Depth First Search Traversal:\n");
    binary_tree_traverse(root, Depth_First_Search_PostOrder);

    printf("\nDeletion Test\n");
    BinaryTree *T = root;
    binary_tree_delete(10, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(7, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(4, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(1, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(2, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(3, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(5, &T);
    binary_tree_traverse(T, Breadth_First_Search);
    binary_tree_delete(6, &T);
    binary_tree_traverse(T, Breadth_First_Search);

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLinkList Queue operations: %f s\n", elapsed);
}