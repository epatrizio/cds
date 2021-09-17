#ifndef HASH_SET_H
#define HASH_SET_H

#define HASH_SET_INITIAL_SIZE 10
#define BUCKET_MAX_SIZE 2

typedef struct _hs_elt {
   char *string;
} hs_elt;

vector_init(hs_elt)  // Will contain elts with same hash_code

typedef hs_elt_vector bucket;

vector_init(bucket)  // The HashSet based on a vector (A vector of buckets)

typedef bucket_vector hash_set;

hash_set hash_set_create(size_t);
void hash_set_destroy(hash_set);
bool hash_set_contains(hash_set, const char*, size_t (*hash_fct)(const char*));  // hash function is a pointer function
hash_set hash_set_add(hash_set, const char*, size_t (*hash_fct)(const char*));
bool hash_set_remove(hash_set, const char*, size_t (*hash_fct)(const char*));

#endif
