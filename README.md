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

* [Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search): Graph traversing algorithm
to easily answer the question "existence of a path between 2 verticies"

* [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search): Another graph traversing algorithm but more complex to answer questions "shortest path in edge number", "edge number between 2 verticies", etc.

* [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm): Another graph algorithm for finding the shortest path between 2 vertices using a distance associated with each edge.\
*Not implemented*

## Run tests

Execute "make compile_test" and that's all!\
I use the framework [ctestfmk](https://github.com/epatrizio/ctestfmk). Read the documentation for more informations.

## Examples

* In /examples/dot directory, there is a simple example of a .dot file generation of a graph.\
Learn more about .dot file, produced by [Graphviz](https://graphviz.org), an open source graph visualization software.

* In /examples/intl directory, there is a complete application of HashMap data structure:\
A little internationalization component.

* In /examples/sort directory, there is a classic and easy application of priority queue data structure:\
The array heap sort. For simplicity, only the int type has been processed.

* In /examples/threads directory, there is a particular example with two objectives :
    1. Another concrete example of using data structures (here, a queue)
    2. An educational simple example of using threads.\
    Here is the purpose : there are vegetable producers who deposit their production in a queue\
    and consumers who serve themselves in this same queue. Producers and consumers work independently.\
        * everyone works in their own thread\
        * waiting conditions are related to production capacity, queue size and consumer needs\
        * in our example, we have 3 producers (apple, pear, banana) and 2 consumers (C1, C2)
        * here is an output example, the result is not deterministic!! (interleaving, scheduler)

        ```console
        C2 >> apple1
        C1 >> apple2
        C2 >> pear1
        C1 >> apple3
        C2 >> apple4
        C2 >> apple5
        C1 >> apple6
        C2 >> pear2
        C1 >> banana1
        C1 >> pear3
        ```

    Learn more about [POSIX Threads](https://en.wikipedia.org/wiki/Pthreads).

### Makefile

In Makefile, you will find :

* Compilation commands (project, tests, examples)

* Lib creation : according to the data structures that you will import in your project,
adjust the command with the correct .c and .h files.\
Watch out for dependencies! For example, vectors are the basis of everything else.
