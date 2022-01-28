#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "linked_list.h"
#include "queue.h"
#include "hash_utils.h"
#include "hash_set.h"
#include "graph.h"

hash_set visited_vertices;

hash_set get_successors(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    graph_bucket b = graph_bucket_vector_get(g, hash_code_modulo(vertex, graph_bucket_vector_size(g), *hash_fct));

    for (unsigned int i=0 ; i<graph_elt_vector_size(b) ; i++) {
        graph_elt elt = graph_elt_vector_get(b, i);
        if (strcmp(vertex, elt.vertex) == 0) {
            return elt.successors;
        }
    }

    return NULL;
}

graph resize_graph(graph g, size_t (*hash_fct)(const char *str))
{
    graph new_g = graph_create(graph_bucket_vector_size(g)*2);

    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++) {
        graph_bucket b = graph_bucket_vector_get(g, i);
        for (unsigned int j=0 ; j<graph_elt_vector_size(b) ; j++) {
            graph_elt elt = graph_elt_vector_get(b, j);
            graph_bucket new_b = graph_bucket_vector_get(new_g, hash_code_modulo(elt.vertex, graph_bucket_vector_size(new_g), *hash_fct));
            // We keep the origin elt. So we don't call graph_destroy.
            graph_elt_vector_add(new_b, graph_elt_vector_size(new_b), elt);
        }
        graph_elt_vector_destroy(b);
    }

    graph_bucket_vector_destroy(g);

    return new_g;
}

graph graph_create(size_t initial_size)
{
    graph g = graph_bucket_vector_create();

    graph_bucket_vector_resize(g, (initial_size>0) ? initial_size : GRAPH_INITIAL_SIZE);

    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++)
        graph_bucket_vector_set(g, i, graph_elt_vector_create());

    return g;
}

void graph_destroy(graph g)
{
    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++) {
        graph_bucket b = graph_bucket_vector_get(g, i);
        for (unsigned int j=0 ; j<graph_elt_vector_size(b) ; j++) {
            graph_elt elt = graph_elt_vector_get(b, j);
            free(elt.vertex);
            hash_set_destroy(elt.successors);
        }
        graph_elt_vector_destroy(b);
    }

    graph_bucket_vector_destroy(g);
}

graph graph_add_vertex(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    graph_bucket b = graph_bucket_vector_get(g, hash_code_modulo(vertex, graph_bucket_vector_size(g), *hash_fct));

    char *cp_vertex = malloc(strlen(vertex)+1);
    strcpy(cp_vertex, vertex);

    graph_elt e = {cp_vertex, hash_set_create(0)};

    for (unsigned int i=0 ; i<graph_elt_vector_size(b) ; i++) {
        graph_elt elt = graph_elt_vector_get(b, i);
        if (strcmp(vertex, elt.vertex) == 0) {
            free(elt.vertex);
            hash_set_destroy(elt.successors);
            graph_elt_vector_remove(b, i);
            break;
        }
    }

    graph_elt_vector_add(b, graph_elt_vector_size(b), e);

    if (graph_elt_vector_size(b) > GRAPH_BUCKET_MAX_SIZE)
        g = resize_graph(g, *hash_fct);

    return g;
}

void graph_add_edge(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    // 0. check: vertex_t must be a vertex!
    graph_bucket b_t = graph_bucket_vector_get(g, hash_code_modulo(vertex_t, graph_bucket_vector_size(g), *hash_fct));
    bool t_is_a_vertex = false;
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_t) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_t, i);
        if (strcmp(vertex_t, elt.vertex) == 0) {
            t_is_a_vertex = true;
            break;
        }
    }
    if (!t_is_a_vertex) return;

    graph_bucket b_s = graph_bucket_vector_get(g, hash_code_modulo(vertex_s, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_s) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_s, i);
        if (strcmp(vertex_s, elt.vertex) == 0) {
            char *cp_vertex_t = malloc(strlen(vertex_t)+1);
            strcpy(cp_vertex_t, vertex_t);
            elt.successors = hash_set_add(elt.successors, cp_vertex_t, *hash_fct);
            break;
        }
    }
}

bool graph_has_edge(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    graph_bucket b_s = graph_bucket_vector_get(g, hash_code_modulo(vertex_s, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_s) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_s, i);
        if (strcmp(vertex_s, elt.vertex) == 0) {
            return hash_set_contains(elt.successors, vertex_t, *hash_fct);
        }
    }
    return false;
}

bool graph_remove_edge(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    graph_bucket b_s = graph_bucket_vector_get(g, hash_code_modulo(vertex_s, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b_s) ; i++) {
        graph_elt elt = graph_elt_vector_get(b_s, i);
        if (strcmp(vertex_s, elt.vertex) == 0) {
            return hash_set_remove(elt.successors, vertex_t, *hash_fct);
        }
    }
    return false;
}

bool graph_remove_vertex(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    // 0. Remove vertex in edges
    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++) {
        graph_bucket b = graph_bucket_vector_get(g, i);
        for (unsigned int j=0 ; j<graph_elt_vector_size(b) ; j++) {
            graph_elt elt = graph_elt_vector_get(b, j);
            hash_set_remove(elt.successors, vertex, *hash_fct);
        }
    }

    graph_bucket b = graph_bucket_vector_get(g, hash_code_modulo(vertex, graph_bucket_vector_size(g), *hash_fct));
    for (unsigned int i=0 ; i<graph_elt_vector_size(b) ; i++) {
        graph_elt elt = graph_elt_vector_get(b, i);
        if (strcmp(vertex, elt.vertex) == 0) {
            free(elt.vertex);
            hash_set_destroy(elt.successors);
            graph_elt_vector_remove(b, i);
            return true;
        }
    }
    return false;
}

// DFS : Depth-First Search
void graph_dfs(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    if (hash_set_contains(visited_vertices, vertex, *hash_fct)) return;

    hash_set_add(visited_vertices, vertex, *hash_fct);

    hash_set successors = get_successors(g, vertex, *hash_fct);
    if (successors == NULL) return;

    for (unsigned int i=0 ; i<hs_bucket_vector_size(successors) ; i++) {
        hs_bucket b = hs_bucket_vector_get(successors, i);
        for (unsigned int j=0 ; j<hs_elt_vector_size(b) ; j++) {
            hs_elt elt = hs_elt_vector_get(b, j);
            graph_dfs(g, elt.string, *hash_fct);
        }
    }
}

bool graph_dfs_exists_path(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    if (visited_vertices != NULL) hash_set_destroy(visited_vertices);
    visited_vertices = hash_set_create(0);
    graph_dfs(g, vertex_s, *hash_fct);
    return hash_set_contains(visited_vertices, vertex_t, *hash_fct);
}

// BFS : Breadth-First Search
void graph_bfs(graph g, const char *vertex, size_t (*hash_fct)(const char *str))
{
    queue q = queue_create();
    queue_push(q, vertex);

    hash_set_add(visited_vertices, vertex, *hash_fct);

    while (!queue_is_empty(q)) {
        char *ver = queue_pop(q);
        hash_set successors = get_successors(g, ver, *hash_fct);
        if (successors == NULL) continue;
        for (unsigned int i=0 ; i<hs_bucket_vector_size(successors) ; i++) {
            hs_bucket b = hs_bucket_vector_get(successors, i);
            for (unsigned int j=0 ; j<hs_elt_vector_size(b) ; j++) {
                hs_elt elt = hs_elt_vector_get(b, j);
                if (!hash_set_contains(visited_vertices, elt.string, *hash_fct)) {
                    queue_push(q, elt.string);
                    hash_set_add(visited_vertices, elt.string, *hash_fct);
                }
            }
        }
    }
}

bool graph_bfs_exists_path(graph g, const char *vertex_s, const char *vertex_t, size_t (*hash_fct)(const char *str))
{
    if (visited_vertices != NULL) hash_set_destroy(visited_vertices);
    visited_vertices = hash_set_create(0);
    graph_bfs(g, vertex_s, *hash_fct);
    return hash_set_contains(visited_vertices, vertex_t, *hash_fct);
}

void graph_dot(graph g)
{
    FILE *file = fopen("graph.dot", "w");
    if (file == NULL) {
      perror("File open error: ");
      return;
    }

    fprintf(file, "digraph {\n");
    // Graph vector loop (for verticies)
    for (unsigned int i=0 ; i<graph_bucket_vector_size(g) ; i++) {
        graph_bucket b = graph_bucket_vector_get(g, i);
        for (unsigned int j=0 ; j<graph_elt_vector_size(b) ; j++) {
            graph_elt elt = graph_elt_vector_get(b, j);
            if (elt.successors == NULL) continue;
            // Successors loop (for one vertex)
            for (unsigned int k=0 ; k<hs_bucket_vector_size(elt.successors) ; k++) {
                hs_bucket bs = hs_bucket_vector_get(elt.successors, k);
                for (unsigned int l=0 ; l<hs_elt_vector_size(bs) ; l++) {
                    hs_elt elt_s = hs_elt_vector_get(bs, l);
                    fprintf(file, "%s -> %s\n", elt.vertex, elt_s.string);
                }
            }
        }
    }
    fprintf(file, "}\n");

    fclose(file);

    return;
}

vector_init_fct(graph_elt)
vector_init_fct(graph_bucket)
