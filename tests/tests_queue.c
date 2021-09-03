#include <stdio.h>
#include <stdlib.h>

#include "tests_queue.h"

void test_queue_empty(const void *function_node)
{
    queue *q = queue_create();

    assert_true(queue_is_empty(q), function_node);

    queue_destroy(q);
}

void test_queue(const void *function_node)
{
    queue *q = queue_create();

    queue_push(q, "push 1");
    queue_push(q, "push 2");
    queue_push(q, "push 3");

    assert_false(queue_is_empty(q), function_node);

    assert_equals_int(3, q->size, function_node);

    assert_equals_charp("push 1", queue_pop(q), function_node);
    assert_equals_int(2, q->size, function_node);
    assert_equals_charp("push 2", queue_pop(q), function_node);
    assert_equals_int(1, q->size, function_node);
    assert_equals_charp("push 3", queue_pop(q), function_node);
    assert_true(queue_is_empty(q), function_node);

    queue_destroy(q);
}
