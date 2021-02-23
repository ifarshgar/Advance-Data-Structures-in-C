# Advanced Data Structures in C programming language. 

## Generic Queue
 With **```void*```** various data types can be handled in C language. 
 This generic queue implementation comes with multiple options as for the queue data type 
 that can be used upon creating and manipulating the queue. 
 Furthermore, the queue is built with LinkedList data structure. 
 Also it is worth mentioning that operations like **push()** and **pop()** has been implemented to have the **time complexity of ```O(1)```**. 

 ```C
 struct Queue {
    void *data;
    struct Queue* next;
 };
 ```
 This implementation of the queue can deal with the most common
 data types such as int, float, double, char, and string. In addition,
 the queue can also hold a BinaryTree which has being defined 
 in this project. The description related to the BinaryTree definition
 can be found below. 
 
 ### Usage
 ```c
 // first of all, two nodes should be created to hold the queue data. 
 Queue *first = NULL;
 Queue *last = NULL;
 
 // e.g. to insert an integer to the queue:    
 int *i = 3;
 queue_push(i, &first, &last, _Integer);
 
 // e.g. to retrieve back an integer value from the queue and delete the integer from the queue:
 int *j = queue_pop(&first, &last);
 ```
 
 
