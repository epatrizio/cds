#ifndef HASH_MAP_H
#define HASH_MAP_H

#define HASH_MAP_INITIAL_SIZE 10
#define HASH_MAP_BUCKET_MAX_SIZE 2

typedef struct _hm_elt {
   char *key;
   char *value;
} hm_elt;

vector_init(hm_elt)

typedef hm_elt_vector hm_bucket;

vector_init(hm_bucket)

typedef hm_bucket_vector hash_map;

hash_map hash_map_create(size_t);
void hash_map_destroy(hash_map);
bool hash_map_contains(hash_map, const char*, size_t (*hash_fct)(const char*));
char* hash_map_get(hash_map, const char*, size_t (*hash_fct)(const char*));
hash_map hash_map_add(hash_map, const char*, const char*, size_t (*hash_fct)(const char*));
bool hash_map_remove(hash_map, const char*, size_t (*hash_fct)(const char*));

#endif
