#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// TODO DOC : Priority queue / heap / why vector

#define priority_queue_struct(T)    \
    typedef T##_vector T##_priority_queue;

#define priority_queue_create_sign(T)                           \
    T##_priority_queue T##_priority_queue_create();             \
    void T##_priority_queue_destroy(T##_priority_queue);        \
    bool T##_priority_queue_is_empty(T##_priority_queue);       \
    void T##_priority_queue_push(T##_priority_queue, const T);  \
    T T##_priority_queue_pop(T##_stack);

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
