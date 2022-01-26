# cds - Data structures in c language (A minimalist implementation)

I update my knowledge by reviewing standard data structures.\
Here is a simple implementation of some of them in C language.

## Vector

Arrays represent the fundamental data structure in computer programming. At the end, everything is array!
So vectors are therefore essential (and the basis of other data structures) and can be seen as dynamic arrays whose dimension can be modified.\
My implementation is inspired by this [blog post](https://constantsmatter.com/posts/generic-ds-c/).
The use of macros allows to define vectors dynamically for primitive and custom types.

## Stack

Stack is the LIFO (Last In First Out) data structure.\
The stack implementation is based on Vector.

## Linked list

Linked list is another fundamental data structure, very relevant and widely used. It's easy to construct and use, but less efficient than an array because pointers are needed to iterate through elements and each element takes more space in memory (specific malloc).\
My implementation is a doubly linked list allowing easy access to first and last element. For simplicity, only the string type has been processed.

## Queue

Queue is the FIFO (First In First Out) data structure.\
The queue implementation is based on Linked List.

## PriorityQueue

Basically, priority queues are equivalent to queues except that when an element is pushed inside, it does not stay at the end but is positioned according to its priority. The pop element is the same.
The priority is the '<' operator.\
The queue implementation is based on Vecotr.

## HashSet

Very quickly, a hash table enables to store elements by applying before a hash function to each element. This subject represent a complete computer science topic! [Learn more](https://en.wikipedia.org/wiki/Hash_table).
The first thing to remember about hash tables: elements can be found in constant time, so it's very powerful.

A HashSet is a specific hash table whose elements are unique.
The HashSet implementation is based on multiple Vectors (On for the hash table, and on for each buckets). For simplicity, only the string type has been processed.

## HashMap

A HashMap is a specific hash table whose elements are couples (key,value), and keys are unique.
The HashMap implementation is based on multiple Vectors (On for the hash table, and on for each buckets). For simplicity, only the string type has been processed.

Implementations are inspired by this [blog post](https://www.journaldev.com/35238/hash-table-in-c-plus-plus) and this another [blog post](https://benhoyt.com/writings/hash-table-in-c/).

## Graph

Graphs are classic data structures used, for example, in navigation systems components.
Graphs are more complex structures than the previous ones, which can be seen as trees generalization composed of vertices and edges. [Learn more](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)).\
My implementation should be seen as a simple discovery.
It based on a new development of a specific hash map that uses hash set.

## Run tests

Execute "make compile_test" and that's all!\
I use the framework [ctestfmk](https://github.com/epatrizio/ctestfmk). Read the documentation for more informations.

## Examples

* In /examples/intl directory, there is a complete application of HashMap data structure:\
A little internationalization component.

* In /examples/sort directory, there is a classic and easy application of priority queue data structure:\
The array heap sort. For simplicity, only the int type has been processed.
