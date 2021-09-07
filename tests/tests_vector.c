#include <stdio.h>
#include <stdlib.h>

#include "tests_vector.h"

void test_char_vector_empty(const void *function_node)
{
    char_vector *v = char_vector_create();

    assert_true(char_vector_is_empty(v), function_node);

    char_vector_destroy(v);
}

void test_char_vector_set(const void *function_node)
{
    char_vector *v = char_vector_create();

    char_vector_set(v, 0, '0');

    assert_equals_int(10, v->capacity, function_node);
    assert_equals_int(1, v->size, function_node);
    assert_equals_char('0', char_vector_get(v, 0), function_node);

    char_vector_set(v, 10, '-');
    char_vector_set(v, 100, '-');
    char_vector_set(v, 5, '5');

    assert_equals_int(10, v->capacity, function_node);
    assert_equals_int(6, v->size, function_node);
    assert_equals_char('0', char_vector_get(v, 0), function_node);
    assert_equals_char('5', char_vector_get(v, 5), function_node);

    char_vector_set(v, 0, 'N');
    char_vector_set(v, 1, '1');
    char_vector_set(v, 7, '7');

    assert_equals_int(10, v->capacity, function_node);
    assert_equals_int(8, v->size, function_node);
    assert_equals_char('N', char_vector_get(v, 0), function_node);
    assert_equals_char('1', char_vector_get(v, 1), function_node);
    assert_equals_char('5', char_vector_get(v, 5), function_node);
    assert_equals_char('7', char_vector_get(v, 7), function_node);

    char_vector_destroy(v);
}

void test_int_vector(const void *function_node)
{
    int_vector *v = int_vector_create();
    int_vector_add(v, 0, 0);
    int_vector_add(v, 1, 10);

    assert_false(int_vector_is_empty(v), function_node);
    assert_equals_int(10, v->capacity, function_node);
    assert_equals_int(2, v->size, function_node);

    assert_equals_int(0, int_vector_get(v, 0), function_node);
    assert_equals_int(10, int_vector_get(v, 1), function_node);

    int_vector_add(v, 2, 20);
    int_vector_add(v, 3, 30);
    int_vector_add(v, 4, 40);
    int_vector_add(v, 5, 50);
    int_vector_add(v, 6, 60);
    int_vector_add(v, 7, 70);
    int_vector_add(v, 8, 80);
    int_vector_add(v, 9, 90);
    int_vector_add(v, 10, 100);

    assert_equals_int(20, v->capacity, function_node);
    assert_equals_int(11, v->size, function_node);

    assert_equals_int(90, int_vector_get(v, 9), function_node);

    int_vector_set(v, 50, 0);
    int_vector_set(v, 9, 99);

    assert_equals_int(99, int_vector_get(v, 9), function_node);

    int_vector_add(v, 6, 66);

    assert_equals_int(20, v->capacity, function_node);
    assert_equals_int(12, v->size, function_node);
    assert_equals_int(66, int_vector_get(v, 6), function_node);
    assert_equals_int(100, int_vector_get(v, 11), function_node);

    int remove = int_vector_remove(v, 6);

    assert_equals_int(20, v->capacity, function_node);
    assert_equals_int(11, v->size, function_node);
    assert_equals_int(66, remove, function_node);
    assert_equals_int(60, int_vector_get(v, 6), function_node);

    int_vector_destroy(v);
}
