#include <stdio.h>
#include <stdlib.h>

#include "tests_utils.h"
#include "tests_graph.h"

void test_graph(const void *function_node)
{
    graph g = graph_create(0);

    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "B", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "C", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "D", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);

    graph_add_edge(g, "A", "B", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "A", "C", HASH_CODE_FCT_CALL);

    assert_true(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);

    assert_false(graph_remove_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_remove_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);

    assert_true(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);

    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);

    assert_false(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);

    assert_true(graph_remove_vertex(g, "A", HASH_CODE_FCT_CALL), function_node);

    graph_destroy(g);
}
