#ifndef VECTOR_H
#define VECTOR_H

#define resizable_array(T)          \
    struct T##_resizable_array {    \
        T *elts;                    \
        size_t capacity;            \
        size_t size;                \
    };

#define vector_struct(T)    \
    typedef struct T##_resizable_array T##_vector;

#define vector_create_sign(T)                           \
    T##_vector *T##_vector_create();                    \
    void T##_vector_destroy(T##_vector*);               \
    bool T##_vector_is_empty(T##_vector*);              \
    void T##_vector_add(T##_vector*, size_t, const T);  \
    T T##_vector_remove(T##_vector*, size_t);           \
    T T##_vector_get(const T##_vector*, size_t);        \
    void T##_vector_set(T##_vector*, size_t, const T);

#define vector_init(T)      \
    resizable_array(T)      \
    vector_struct(T)        \
    vector_create_sign(T)

vector_init(int)
vector_init(short)
vector_init(long)
//vector_init(float)
//vector_init(double)
vector_init(char)

#endif
