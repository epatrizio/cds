#ifndef TESTS_VECTOR_H
#define TESTS_VECTOR_H

#include "lib/ctestfmk.h"
#include "../src/vector.h"

typedef struct _custom_struct {
   int idx;
   char *string;
} custom_struct;

vector_init(custom_struct)

void test_char_vector_empty(const void*);
void test_double_vector_resize(const void*);
void test_int_vector(const void*);
void test_custom_struct_vector(const void*);

#endif