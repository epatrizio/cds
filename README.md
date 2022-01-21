# cds - Data structures in c language (A minimalist implementation)

I update my knowledge by reviewing standard data structures. Here is a simple implementation of some of them in C language.

## Vector data structure

Arrays represent the fundamental data structure in computer programming. At the end, everything is array!
So vectors are therefore essential (and the basis of other data structures) and can be seen as dynamic arrays whose dimension can be modified.
The implementation is inspired by this [blog post](https://constantsmatter.com/posts/generic-ds-c/).
The use of macros allows to define vectors dynamically for primitive and custom types.

## Stack data structure

Stack is the LIFO (Last In First Out) data structure.
The stack implementation is based on Vector.

## Linked list data structure

Linked list is another fundamental data structure, very relevant and widely used. It's easy to construct and use, but less efficient than an array because pointers are needed to iterate through elements and each element takes more space in memory (specific malloc).
My implementation is a doubly linked list allowing easy access to first and last element. For simplicity, only the string type has been processed.

## Queue data structure

Queue is the FIFO (First In First Out) data structure.
The queue implementation is based on Linked List.

## HashSet data structure

Very quickly, a hash table enables to store elements by applying before a hash function to each element. This subject represent a full computer science topic! [Learn more](https://en.wikipedia.org/wiki/Hash_table).
The first thing to remember about hash tables: elements can be found in constant time, so it's very powerful.

A HashSet is a specific hash table whose elements are unique.
The HashSet implementation is based on multiple Vectors (On for the hash table, and on for each buckets). For simplicity, only the string type has been processed.

## HashMap data structure

A HashMap is a specific hash table whose elements are couples (key,value), and keys are unique.
The HashMap implementation is based on multiple Vectors (On for the hash table, and on for each buckets). For simplicity, only the string type has been processed.

Implementations are inspired by this [blog post](https://www.journaldev.com/35238/hash-table-in-c-plus-plus) and this another [blog post](https://benhoyt.com/writings/hash-table-in-c/).

## Run tests

Execute "make compile_test" and that's all!
I use the framework [ctestfmk](https://github.com/epatrizio/ctestfmk). Read the documentation for more informations.

## Example

In /example directory, you can find a complete application of HashMap data structure : A little internationalization component.
