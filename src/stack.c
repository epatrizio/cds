#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "stack.h"

#define stack_create_fct(T)         \
    T##_stack T##_stack_create() {  \
        return T##_vector_create(); \
    }

#define stack_destroy_fct(T)                \
    void T##_stack_destroy(T##_stack s)     \
    {                                       \
        T##_vector_destroy(s);              \
    }

#define stack_is_empty_fct(T)               \
    bool T##_stack_is_empty(T##_stack s)    \
    {                                       \
        return T##_vector_is_empty(s);      \
    }

#define stack_push_fct(T)                           \
    void T##_stack_push(T##_stack s, const T elt)   \
    {                                               \
        T##_vector_add(s, s->size, elt);            \
    }

#define stack_pop_fct(T)                        \
    T T##_stack_pop(T##_stack s)                \
    {                                           \
        return T##_vector_remove(s, s->size-1); \
    }

#define stack_init_fct(T)   \
    stack_create_fct(T)     \
    stack_destroy_fct(T)    \
    stack_is_empty_fct(T)   \
    stack_push_fct(T)       \
    stack_pop_fct(T)

stack_init_fct(int)
stack_init_fct(short)
stack_init_fct(long)
stack_init_fct(float)
stack_init_fct(double)
stack_init_fct(char)
