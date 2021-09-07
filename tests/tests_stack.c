#include <stdio.h>
#include <stdlib.h>

#include "tests_stack.h"

void test_char_stack_empty(const void *function_node)
{
    char_stack *s = char_stack_create();

    assert_true(char_stack_is_empty(s), function_node);

    char_stack_destroy(s);
}

void test_int_stack(const void *function_node)
{
    int_stack *s = int_stack_create();

    int_stack_push(s, 0);
    int_stack_push(s, 1);
    int_stack_push(s, 2);

    assert_false(int_stack_is_empty(s), function_node);
    assert_equals_int(10, s->capacity, function_node);
    assert_equals_int(3, s->size, function_node);

    int pop = int_stack_pop(s);

    assert_equals_int(10, s->capacity, function_node);
    assert_equals_int(2, s->size, function_node);
    assert_equals_int(2, pop, function_node);

    int_stack_destroy(s);
}
