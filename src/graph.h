#ifndef GRAPH_H
#define GRAPH_H

#define GRAPH_INITIAL_SIZE 10
#define GRAPH_BUCKET_MAX_SIZE 2

/*
Graph can be modeled as a hash map : key=vertex:string / value=successors-edges:hash_set
But the current hash map DS don't allow this model because (key,value) is fixed.
That's why, this impementation is a new hash map development.
*/

typedef struct _graph_elt {
   char *vertex;
   hash_set successors;
} graph_elt;

vector_init(graph_elt)

typedef graph_elt_vector graph_bucket;

vector_init(graph_bucket)

typedef graph_bucket_vector graph;

graph graph_create(size_t);
void graph_destroy(graph);
graph graph_add_vertex(graph, const char*, size_t (*hash_fct)(const char*));
void graph_add_edge(graph, const char*, const char*, size_t (*hash_fct)(const char*));
bool graph_has_edge(graph, const char*, const char*, size_t (*hash_fct)(const char*));
bool graph_remove_edge(graph, const char*, const char*, size_t (*hash_fct)(const char*));
bool graph_remove_vertex(graph, const char*, size_t (*hash_fct)(const char*));
void graph_dfs(graph, const char*, size_t (*hash_fct)(const char*));
bool graph_dfs_exists_path(graph, const char*, const char*, size_t (*hash_fct)(const char*));
void graph_bfs(graph, const char*, size_t (*hash_fct)(const char*));
bool graph_bfs_exists_path(graph, const char*, const char*, size_t (*hash_fct)(const char*));
void graph_dot(graph);

#endif
