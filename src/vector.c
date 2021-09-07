#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define vector_create_fct(T)                            \
    T##_vector *T##_vector_create() {                   \
        T##_vector *v = malloc(sizeof(T##_vector));     \
        v->elts = malloc(10 * sizeof(T));               \
        v->capacity = 10;                               \
        v->size = 0;                                    \
        return v;                                       \
    }

#define vector_destroy_fct(T)               \
    void T##_vector_destroy(T##_vector* v)  \
    {                                       \
        free(v->elts);                      \
        free(v);                            \
    }

#define vector_is_empty_fct(T)              \
    bool T##_vector_is_empty(T##_vector* v) \
    {                                       \
        return (v->size == 0);              \
    }

#define vector_add_fct(T)                                           \
    void T##_vector_add(T##_vector* v, size_t index, const T elt)   \
    {                                                               \
        if (index > v->size) return;                                \
        if (v->size == v->capacity) {                               \
            v->capacity *= 2;                                       \
            v->elts = realloc(v->elts, v->capacity * sizeof(T));    \
        }                                                           \
        if (index < v->size) {                                      \
            for (unsigned int i = v->size-1 ; i >= index ; i--) {   \
                v->elts[i+1] = v->elts[i];                          \
            }                                                       \
        }                                                           \
        v->elts[index] = elt;                                       \
        v->size++;                                                  \
    }

#define vector_remove_fct(T)                                    \
    T T##_vector_remove(T##_vector* v, size_t index)            \
    {                                                           \
        if (index > v->size) return NULL;                       \
        T elt = v->elts[index];                                 \
        if (index < v->size) {                                  \
            for (unsigned int i = index ; i < v->size ; i++) {  \
                v->elts[i] = v->elts[i+1];                      \
            }                                                   \
        }                                                       \
        v->size--;                                              \
        return elt;                                             \
    }

#define vector_get_fct(T)                               \
    T T##_vector_get(const T##_vector* v, size_t index) \
    {                                                   \
        if (index > v->size) return NULL;               \
        return v->elts[index];                          \
    }

#define vector_set_fct(T)                                           \
    void T##_vector_set(T##_vector* v, size_t index, const T elt)   \
    {                                                               \
        if (index >= v->capacity) return;                           \
        if (index >= v->size) v->size = index+1;                    \
        v->elts[index] = elt;                                       \
    }

#define vector_init_fct(T)  \
    vector_create_fct(T)    \
    vector_destroy_fct(T)   \
    vector_is_empty_fct(T)  \
    vector_add_fct(T)       \
    vector_remove_fct(T)    \
    vector_get_fct(T)       \
    vector_set_fct(T)

vector_init_fct(int)
vector_init_fct(short)
vector_init_fct(long)
//vector_init_fct(float)
//vector_init_fct(double)
vector_init_fct(char)
