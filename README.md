# Advanced Data Structures in C programming language. 

## Generic Queue
 Queue is an abstract data structure. 
 A queue is open at both its ends. One end is always used 
 to insert data (enqueue) and the other is used to remove 
 data (dequeue). Queue follows First-In-First-Out methodology, 
 i.e., the data item stored first will be accessed first.
 
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
 data types such as ```int```, ```float```, ```double```, ```char```, and ```string```. In addition,
 the queue can also hold a ```BinaryTree``` which has being defined 
 in this project. The description related to the BinaryTree definition
 can be found below. 
 
 
![Queue](https://github.com/ifarshgar/Advance-Data-Structures-in-C/blob/main/Queue-illustration.jpg)

 
 ### Usage
 ```c
 // first of all, two nodes should be created to hold the queue data. 
 Queue *first = NULL;
 Queue *last = NULL;
 
 // e.g. to insert an integer to the queue:    
 int *i = 3;
 queue_push(i, &first, &last, _Integer);
 
 // e.g. to retrieve back an integer value and delete it from the queue:
 int *j = queue_pop(&first, &last);
 ```
 
 # Simple Queue
 Sometimes all that a simple program needs is just an easy to use 
 queue implementation. This library offers a very simple and fast 
 implementation of the queue data structure with a fast insertion
 and deletion. Also, getting the size of the queue is super fast since
 the library holds the number of times that push and pop functions are called 
 therefore it knows the exact number of items existed in the queue structure. 
 
 Furthermore, the programmer doesn't need to deal with the queue pointers anymore.
 The library creates two nodes for holding the data of the queue automatically. Hence, 
 this queue library function calls do not even need to take any arguments other than
 a value that needs to be pushed into the queue in push function. Therefore, this is the 
 simplest that a queue implementation can get in C language. 

 However, the only problem that this simple queue library is facing is that there can be 
 only one active simple queue in the program at the same time. This is because of the 
 fact that C language is not Object Oriented and creating different instances of a 
 library is not possible. The generic queue implementation takes two pointers representing 
 the head and the tail of the queue and therefore by passing different pointers to the queue
 multiple queues can exist at the same time but this is not the case about the simple queue library. 
