#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

/*
Basically, priority queue should be implemented by a BST (Binary Search Tree).
But, heap structure is good enough, and, by construction, heap tree is almost perfect
so heap can be implemented with a vector (array).
*/

#define priority_queue_struct(T)    \
    typedef T##_vector T##_priority_queue;

#define priority_queue_create_sign(T)                           \
    T##_priority_queue T##_priority_queue_create();             \
    void T##_priority_queue_destroy(T##_priority_queue);        \
    bool T##_priority_queue_is_empty(T##_priority_queue);       \
    void T##_priority_queue_push(T##_priority_queue, const T);  \
    T T##_priority_queue_pop(T##_priority_queue);

#define priority_queue_init(T)      \
    priority_queue_struct(T)        \
    priority_queue_create_sign(T)

priority_queue_init(int)
priority_queue_init(short)
priority_queue_init(long)
priority_queue_init(float)
priority_queue_init(double)
priority_queue_init(char)

#endif
