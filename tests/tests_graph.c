#include <stdio.h>
#include <stdlib.h>

#include "tests_utils.h"
#include "tests_graph.h"

void test_graph(const void *function_node)
{
    graph g = graph_create(2);  // 2 > force resize

    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "B", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "C", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "D", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);

    graph_add_edge(g, "A", "B", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "A", "C", HASH_CODE_FCT_CALL);

    g = graph_add_vertex(g, "E", HASH_CODE_FCT_CALL);   // Resize after add edge!    

    // Check add vertices and edges
    assert_true(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);

    // Check remove edges    
    assert_false(graph_remove_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_remove_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);

    assert_true(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);

    // When add a already existing vertex, everything starts again from beginning (remove all edges)
    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);

    assert_false(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "D", HASH_CODE_FCT_CALL), function_node);

    // check remove vertex
    graph_add_edge(g, "A", "B", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "A", "C", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "A", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "C", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "D", HASH_CODE_FCT_CALL);

    assert_true(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "B", "A", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "B", "C", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "B", "D", HASH_CODE_FCT_CALL), function_node);

    assert_false(graph_remove_vertex(g, "Z", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_remove_vertex(g, "A", HASH_CODE_FCT_CALL), function_node);

    assert_false(graph_has_edge(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "A", "C", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_has_edge(g, "B", "A", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "B", "C", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_has_edge(g, "B", "D", HASH_CODE_FCT_CALL), function_node);

    graph_destroy(g);
}

void test_graph_dfs(const void *function_node)
{
    graph g = graph_create(0);

    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "B", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "C", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "D", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "E", HASH_CODE_FCT_CALL);

    graph_add_edge(g, "A", "B", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "C", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "E", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "C", "D", HASH_CODE_FCT_CALL);

    assert_true(graph_dfs_exists_path(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_dfs_exists_path(g, "A", "D", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_dfs_exists_path(g, "A", "E", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_dfs_exists_path(g, "B", "E", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_dfs_exists_path(g, "B", "A", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_dfs_exists_path(g, "C", "E", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_dfs_exists_path(g, "E", "A", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_dfs_exists_path(g, "E", "B", HASH_CODE_FCT_CALL), function_node);

    graph_destroy(g);
}

void test_graph_bfs(const void *function_node)
{
    graph g = graph_create(0);

    g = graph_add_vertex(g, "A", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "B", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "C", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "D", HASH_CODE_FCT_CALL);
    g = graph_add_vertex(g, "E", HASH_CODE_FCT_CALL);

    graph_add_edge(g, "A", "B", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "C", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "B", "E", HASH_CODE_FCT_CALL);
    graph_add_edge(g, "C", "D", HASH_CODE_FCT_CALL);

    assert_true(graph_bfs_exists_path(g, "A", "B", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_bfs_exists_path(g, "A", "D", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_bfs_exists_path(g, "A", "E", HASH_CODE_FCT_CALL), function_node);
    assert_true(graph_bfs_exists_path(g, "B", "E", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_bfs_exists_path(g, "B", "A", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_bfs_exists_path(g, "C", "E", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_bfs_exists_path(g, "E", "A", HASH_CODE_FCT_CALL), function_node);
    assert_false(graph_bfs_exists_path(g, "E", "B", HASH_CODE_FCT_CALL), function_node);

    graph_destroy(g);
}