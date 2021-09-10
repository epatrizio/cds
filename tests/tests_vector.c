#include <stdio.h>
#include <stdlib.h>

#include "tests_vector.h"

void test_char_vector_empty(const void *function_node)
{
    char_vector v = char_vector_create();

    assert_true(char_vector_is_empty(v), function_node);
    assert_equals_int(MIN_CAPACITY, v->capacity, function_node);
    assert_equals_int(0, char_vector_size(v), function_node);

    char_vector_destroy(v);
}

void test_double_vector_resize(const void *function_node)
{
    double_vector v = double_vector_create();

    assert_true(double_vector_is_empty(v), function_node);
    assert_equals_int(MIN_CAPACITY, v->capacity, function_node);
    assert_equals_int(0, double_vector_size(v), function_node);

    double_vector_resize(v, 5);

    assert_false(double_vector_is_empty(v), function_node);
    assert_equals_int(MIN_CAPACITY, v->capacity, function_node);
    assert_equals_int(5, double_vector_size(v), function_node);

    double_vector_resize(v, 12);

    assert_false(double_vector_is_empty(v), function_node);
    assert_equals_int(MIN_CAPACITY*2, v->capacity, function_node);
    assert_equals_int(12, double_vector_size(v), function_node);

    double_vector_resize(v, 100);

    assert_false(double_vector_is_empty(v), function_node);
    assert_equals_int(100, v->capacity, function_node);
    assert_equals_int(100, double_vector_size(v), function_node);

    double_vector_destroy(v);
}

void test_int_vector(const void *function_node)
{
    int_vector v = int_vector_create();
    int_vector_add(v, 0, 0);
    int_vector_add(v, 1, 10);

    assert_false(int_vector_is_empty(v), function_node);
    assert_equals_int(MIN_CAPACITY, v->capacity, function_node);
    assert_equals_int(2, int_vector_size(v), function_node);

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

    assert_equals_int(MIN_CAPACITY*2, v->capacity, function_node);
    assert_equals_int(11, int_vector_size(v), function_node);

    assert_equals_int(90, int_vector_get(v, 9), function_node);

    int_vector_set(v, 9, 99);

    assert_equals_int(99, int_vector_get(v, 9), function_node);

    int_vector_add(v, 6, 66);

    assert_equals_int(MIN_CAPACITY*2, v->capacity, function_node);
    assert_equals_int(12, int_vector_size(v), function_node);
    assert_equals_int(66, int_vector_get(v, 6), function_node);
    assert_equals_int(100, int_vector_get(v, 11), function_node);

    int remove = int_vector_remove(v, 6);

    assert_equals_int(MIN_CAPACITY*2, v->capacity, function_node);
    assert_equals_int(11, int_vector_size(v), function_node);
    assert_equals_int(66, remove, function_node);
    assert_equals_int(60, int_vector_get(v, 6), function_node);
    assert_equals_int(100, int_vector_get(v, 10), function_node);

    int_vector_destroy(v);
}
