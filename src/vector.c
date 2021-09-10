#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define vector_create_fct(T)                        \
    T##_vector T##_vector_create() {                \
        T##_vector v = malloc(sizeof(T##_vector));  \
        v->elts = malloc(MIN_CAPACITY * sizeof(T)); \
        v->capacity = MIN_CAPACITY;                 \
        v->size = 0;                                \
        return v;                                   \
    }

#define vector_destroy_fct(T)               \
    void T##_vector_destroy(T##_vector v)   \
    {                                       \
        free(v->elts);                      \
        free(v);                            \
    }

#define vector_size_fct(T)                  \
    size_t T##_vector_size(T##_vector v)    \
    {                                       \
        return v->size;                     \
    }

#define vector_is_empty_fct(T)              \
    bool T##_vector_is_empty(T##_vector v)  \
    {                                       \
        return (T##_vector_size(v) == 0);   \
    }

#define vector_resize_fct(T)                                                \
    void T##_vector_resize(T##_vector v, size_t size)                       \
    {                                                                       \
        if (size > v->capacity) {                                           \
            v->capacity = (size > v->capacity*2) ? size : v->capacity*2;    \
            v->elts = realloc(v->elts, v->capacity * sizeof(T));            \
        }                                                                   \
        v->size = size;                                                     \
    }

#define vector_get_fct(T)                               \
    T T##_vector_get(const T##_vector v, size_t index)  \
    {                                                   \
        assert(index < v->size);                        \
        return v->elts[index];                          \
    }

#define vector_set_fct(T)                                           \
    void T##_vector_set(T##_vector v, size_t index, const T elt)    \
    {                                                               \
        assert(index < v->size);                                    \
        v->elts[index] = elt;                                       \
    }

#define vector_add_fct(T)                                           \
    void T##_vector_add(T##_vector v, size_t index, const T elt)    \
    {                                                               \
        assert(index <= v->size);                                   \
        T##_vector_resize(v, v->size+1);                            \
        if (index < v->size-1) {                                    \
            for (unsigned int i = v->size-2 ; i >= index ; i--) {   \
                T##_vector_set(v, i+1, T##_vector_get(v, i));       \
            }                                                       \
        }                                                           \
        v->elts[index] = elt;                                       \
    }

#define vector_remove_fct(T)                                        \
    T T##_vector_remove(T##_vector v, size_t index)                 \
    {                                                               \
        assert(index < v->size);                                    \
        T elt = T##_vector_get(v, index);                           \
        if (index < v->size-1) {                                    \
            for (unsigned int i = index ; i < v->size-1 ; i++) {    \
                T##_vector_set(v, i, T##_vector_get(v, i+1));       \
            }                                                       \
        }                                                           \
        T##_vector_resize(v, v->size-1);                            \
        return elt;                                                 \
    }

#define vector_init_fct(T)  \
    vector_create_fct(T)    \
    vector_destroy_fct(T)   \
    vector_is_empty_fct(T)  \
    vector_size_fct(T)      \
    vector_resize_fct(T)    \
    vector_get_fct(T)       \
    vector_set_fct(T)       \
    vector_add_fct(T)       \
    vector_remove_fct(T)

vector_init_fct(int)
vector_init_fct(short)
vector_init_fct(long)
vector_init_fct(float)
vector_init_fct(double)
vector_init_fct(char)
