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
void test_binary_search_tree_library();
void test_generic_vector_library();

int main() {
    printf(".... Data Structures .....\n\n");

    test_array_lib();
    test_helper();
    test_sequential_search_library();
    test_binary_search_library();
    test_simple_queue_library();
    test_simple_stack_library();
    test_generic_queue_library();
    test_binary_tree_library();
    test_binary_search_tree_library();
    test_generic_vector_library();

    free(data);
    return 0;
}

void test_generic_vector_library() {
    printf("\n.... Test Generic Vector Library .....\n");

    Vector *first = NULL;
    Vector *last = NULL;

    // vector_push test
    int *v = (int *) malloc(sizeof(int));
    *v = 10;
    vector_push(&first, &last, v);
    v = (int *) malloc(sizeof(int));
    *v = 20;
    vector_push(&first, &last, v);
    v = (int *) malloc(sizeof(int));
    *v = 30;
    vector_push(&first, &last, v);
    v = (int *) malloc(sizeof(int));
    *v = 40;
    vector_push(&first, &last, v);
    v = (int *) malloc(sizeof(int));
    *v = 50;
    int res = vector_push(&first, &last, v);
    if(res)
        printf("Data inserted into the vector successfully!\n");


    // vector_insert test
    v = (int *) malloc(sizeof(int));
    *v = 5;
    vector_insert(&first, &last, v,0);              // insert at the first position
    v = (int *) malloc(sizeof(int));
    *v = 60;
    vector_insert(&first, &last, v, vector_size(first));  // insert at the last position
    v = (int *) malloc(sizeof(int));
    *v = 55;
    vector_insert(&first, &last, v,vector_size(first)-1); // one to the last position
    v = (int *) malloc(sizeof(int));
    *v = 25;
    vector_insert(&first, &last, v,3);  // insert to the middle

    // vector_get test
    int *r;
    for(int i=0; i<vector_size(first); i++) {
        r = vector_get(first, i);
        if(r != NULL)
            printf("Vector[%d]: %d\n", i, *r);
    }

    printf("1-Size of the vector: %d\n", vector_size(first));
    // vector_delete test
    int size = vector_size(first);
    for(int i=0; i<size/2; i++) {
        int *deleted = vector_get(first, 0);
        int p = vector_delete(&first, &last, 0);
        if(p == 1)
            printf("vector_delete(%d)\n", *deleted);
    }

    printf("2-Size of the vector: %d\n", vector_size(first));
    // vector_pop test
    for(int i=0; i<size/2+1; i++) {
        r = vector_pop(&first, &last);
        if(r != NULL)
            printf("vector_pop(): %d\n", *r);
    }

    printf("3-Size of the vector: %d\n", vector_size(first));
    // trying to access the vector while it is empty
    r = vector_pop(&first, &last);
    if(r != NULL)
        printf("vector_pop(): %d\n", *r);
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
    sequential_search(TO_FIND, data, SIZE);
    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sequential search: %f s\n", elapsed);
}

void test_binary_search_library() {
    printf("\n.... Test Search Libraries .....\n");
    clock_t start, end;
    start = clock();
    binary_search(TO_FIND, data, SIZE);
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
    BinaryTree *bt = binary_tree_init();
    bt->data = 1;
    void *vvv = bt;
    queue_push(vvv, &first2, &last2);
    printf("\n- Generic Queue Type - BinaryTree\n");
    queue_print(first2, _BinaryTree);
    BinaryTree *bt2 = binary_tree_init();
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

void test_binary_search_tree_library() {
    printf("\n.... Test Binary Search Tree Library .....\n");

    clock_t start, end;
    start = clock();
    BinaryTree *root = NULL;

    binary_search_tree_insert(30, &root);
    binary_search_tree_insert(15, &root);
    binary_search_tree_insert(20, &root);
    binary_search_tree_insert(10, &root);
    binary_search_tree_insert(21, &root);
    binary_search_tree_insert(35, &root);
    binary_search_tree_insert(40, &root);
    binary_search_tree_insert(32, &root);
    binary_search_tree_insert(18, &root);

    printf("-In-order Depth First Search Traversal:\n");
    binary_tree_traverse(root, Depth_First_Search_InOrder);

    printf("\nDeletion Test\n");
    BinaryTree *T = root;
    binary_search_tree_delete(30, &T);
    printf("Node<%d> is deleted!\n", 30);
    binary_tree_traverse(root, Depth_First_Search_InOrder);
    binary_search_tree_delete(20, &T);
    printf("Node<%d> is deleted!\n", 20);
    binary_tree_traverse(root, Depth_First_Search_InOrder);
    binary_search_tree_delete(40, &T);
    printf("Node<%d> is deleted!\n", 40);
    binary_tree_traverse(root, Depth_First_Search_InOrder);
    binary_search_tree_delete(15, &T);
    printf("Node<%d> is deleted!\n", 15);
    binary_tree_traverse(root, Depth_First_Search_InOrder);


    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLinkList Queue operations: %f s\n", elapsed);
}