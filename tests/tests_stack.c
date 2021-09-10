#include <stdio.h>
#include <stdlib.h>

#include "tests_stack.h"

void test_char_stack_empty(const void *function_node)
{
    char_stack s = char_stack_create();

    assert_true(char_stack_is_empty(s), function_node);

    char_stack_destroy(s);
}

void test_float_stack(const void *function_node)
{
    float_stack s = float_stack_create();

    float_stack_push(s, 0.0);
    float_stack_push(s, 1000.0);
    float_stack_push(s, 2000.0);

    assert_false(float_stack_is_empty(s), function_node);

    float pop = float_stack_pop(s);
    assert_equals_double(2000.0, pop, function_node);

    pop = float_stack_pop(s);
    assert_equals_double(1000.0, pop, function_node);

    pop = float_stack_pop(s);
    assert_equals_double(0.0, pop, function_node);

    assert_true(float_stack_is_empty(s), function_node);

    float_stack_destroy(s);
}
