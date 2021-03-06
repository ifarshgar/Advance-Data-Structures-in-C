# Advanced Data Structures in C programming language. 

## Generic Vector
 Vectors are same as dynamic arrays with the ability to resize itself 
 automatically when an element is inserted or deleted. 
 Vector elements can be accessed and traversed easily. 
 In this generic vector implementation, data can be inserted at 
 any arbitrary index and thus lets the developer who is using the library 
 to store data much more flexibly. 
 Inserting at the begining and ending has the time complexity of O(1).
 However, insertion takes a linear time if it happens in the middle of the vector, 
 as the nodes need to be traveresed and the exact insertion location be found. 
 Also, removing the first and the last element takes O(1) time because no vector traverse is needed. 
 And, erasing in the middle is again linear in terms of time complexity. 

 With **```void*```** various data types can be handled and manipulated in C language. 
 This generic vector implementation uses void* to store data and it accepts 
 literally all kinds of data even pointer to other data structures and structs. 
 Furthermore, the vector is built with LinkedList data structure and it is worth mentioning that 
 operations like **push()** and **pop()** has been implemented to have the **time complexity of ```O(1)```**.
 Also, insertion, deletion, getting, and setting data at any other location within the vector has been made possible 
 with the most efficient time complexity possible.  

 ```C
 struct Vector {
    void *data;
    Vector *next;
    Vector *prev;
 };
 ```

 <!-- ![Queue](https://github.com/ifarshgar/Advance-Data-Structures-in-C/blob/main/vector.png) -->
 <img src="vector.png" alt="vector image" class="inline"/>


 ### Usage
 ```C
 // Two nodes are required to interact with the vector as shown below:
 Vector *first = NULL;
 Vector *last = NULL;
 
 // to insert an integer to the vector
 int *v = (int *) malloc(sizeof(int));
 *v = 10;
 vector_push(&first, &last, v);
 
 // to retrieve back the data
 int *data = vector_get(first, index);

 // to delete the data
 vector_delete(&first, &last, index);
 ```



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
 
 
<!-- ![Queue](https://github.com/ifarshgar/Advance-Data-Structures-in-C/blob/main/Queue-illustration.jpg) -->
<img src="Queue-illustration.jpg" alt="vector image" class="inline"/>

 
 ### Usage
 ```c
 // first of all, two nodes should be created to hold the queue data. 
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

 // string
 char *s = (char *) malloc(20 * sizeof(char));
 strcpy(s, "Aley");
 queue_push(s, &first, &last);
 char *qs = queue_pop(&first, &last);
 printf("\n- Generic Queue Type - String - %s\n", qs);
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

 ```C
 // to insert data to the queue
 simple_queue_push(data);

 // to retrieve data
 int data = simple_queue_pop();
 ```

 As you notice from the code above, using this structure
 is extremely easy and one does not even need to hold 
 on to the nodes of the queue to interact with 
 this library. 

# Binary Tree
 In computer science, a binary tree is a tree data structure in which 
 each node has at most two children, which are referred to as the 
 left child and the right child.

 In the implementation of the binary tree, 
 [Generic Queue Library](Generic%20Queue) played
 an important role to keep the node data while traversing the nodes of the
 tree. 

 This implementation also supports all the conventional traversal methods.
 ```c
 enum TraverseType {
    Breadth_First_Search = 1,
    Depth_First_Search_InOrder = 2,
    Depth_First_Search_PreOrder = 3,
    Depth_First_Search_PostOrder = 4
 };
 ```

 The library has two types of insertion and deletion. 
 One of them is with respect to the completeness of 
 the tree and in order of the way that nodes were added to the tree.
 
 ```c
 // insertion with respect to the completeness of the tree.
 void binary_tree_insert(int data, BinaryTree **T);
 void binary_tree_delete(int data, BinaryTree **T);
 ``` 

 The other type is binary search tree insertion and deletion.
 A binary search tree, also called an ordered or sorted binary tree, 
 is a rooted binary tree whose internal nodes each store a key 
 greater than all the keys in the node's left subtree and less 
 than those in its right subtree.
 
 ```c
 void binary_search_tree_insert(int data, BinaryTree **T);   // binary search tree insertion
 void binary_search_tree_delete(int data, BinaryTree **T);   // binary search tree deletion
 ``` 

<br>

## License

 Unless otherwise specified, everything in this repository is covered by the following licence:

 [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

 [View Copyright](LICENSE)

 
 <br><br>
 <a href="https://www.buymeacoffee.com/ifar" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>
