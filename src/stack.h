#ifndef STACK_H
#define STACK_H

#define stack_struct(T)    \
    typedef T##_vector T##_stack;

#define stack_create_sign(T)                    \
    T##_stack *T##_stack_create();              \
    void T##_stack_destroy(T##_stack*);         \
    void T##_stack_push(T##_stack*, const T);   \
    T T##_stack_pop(T##_stack*);

#define stack_init(T)       \
    stack_struct(T)         \
    stack_create_sign(T)

stack_init(int)
stack_init(short)
stack_init(long)
//stack_init(float)
//stack_init(double)
stack_init(char)

#endif
