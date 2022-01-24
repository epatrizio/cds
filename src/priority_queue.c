#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "priority_queue.h"

#define priority_queue_create_fct(T)                    \
    T##_priority_queue T##_priority_queue_create() {    \
        return T##_vector_create();                     \
    }

#define priority_queue_destroy_fct(T)                       \
    void T##_priority_queue_destroy(T##_priority_queue pq)  \
    {                                                       \
        T##_vector_destroy(pq);                             \
    }

#define priority_queue_is_empty_fct(T)                      \
    bool T##_priority_queue_is_empty(T##_priority_queue pq) \
    {                                                       \
        return T##_vector_is_empty(pq);                     \
    }

// The data structure is managed as a heap.
// So, insertion at the end (pq->size), and after, move up (comparaison with parent).
#define priority_queue_push_fct(T)                                      \
    void T##_priority_queue_push(T##_priority_queue pq, const T elt)    \
    {                                                                   \
        int i = pq->size;                                               \
        T##_vector_resize(pq, pq->size+1);                              \
        while (i > 0) {                                                 \
            int parent_i = (i-1)/2;                                     \
            T e = T##_vector_get(pq, parent_i);                         \
            if (e <= elt) break;                                        \
            T##_vector_set(pq, i, e);                                   \
            i = parent_i;                                               \
        }                                                               \
        T##_vector_set(pq, i, elt);                                     \
    }

// TODO Doc aritmetic 2*i+1 ...
#define priority_queue_pop_fct(T)                   \
    T T##_priority_queue_pop(T##_priority_queue pq) \
    {                                               \
        assert(!T##_priority_queue_is_empty(pq));   \
        T e0 = T##_vector_get(pq, 0);               \
        T e = T##_vector_get(pq, pq->size-1);       \
        T##_vector_resize(pq, pq->size-1);          \
        int i = pq->size;                           \
        if (i > 0) {                                \
            int init_i = 0;                         \
            while (true) {                          \
                int left_i = 2 * init_i + 1;        \
                int right_i = 2 * init_i + 2;       \
                if (left_i >= i) break;             \
                if (right_i < i && T##_vector_get(pq, left_i) > T##_vector_get(pq, right_i)) \
                    left_i++;   \
                if (e <= T##_vector_get(pq, left_i)) break;             \
                T##_vector_set(pq, init_i, T##_vector_get(pq, left_i)); \
                init_i = left_i;                                        \
            }                                                           \
            T##_vector_set(pq, init_i, e);                              \
        }                                                               \
        return e0;                                                      \
    }

#define priority_queue_init_fct(T)   \
    priority_queue_create_fct(T)     \
    priority_queue_destroy_fct(T)    \
    priority_queue_is_empty_fct(T)   \
    priority_queue_push_fct(T)       \
    priority_queue_pop_fct(T)

priority_queue_init_fct(int)
priority_queue_init_fct(short)
priority_queue_init_fct(long)
priority_queue_init_fct(float)
priority_queue_init_fct(double)
priority_queue_init_fct(char)
