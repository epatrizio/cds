#include <stdio.h>
#include <stdlib.h>

#include "tests_hash_set.h"

#define HASH_CODE_FCT_CALL (size_t (*)(const char*))(hash_code)

// programmer defines his own hash function (same signature)
// Here is an example http://www.cse.yorku.ca/~oz/hash.html
size_t hash_code(const char *str)
{
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void test_hash_set(const void *function_node)
{
    hash_set hs = hash_set_create(2);

    assert_false(hash_set_contains(hs, "not_exists", HASH_CODE_FCT_CALL), function_node);

    hs = hash_set_add(hs, "str_1", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_2", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_3", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_4", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_5", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_6", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_7", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_8", HASH_CODE_FCT_CALL);
    hs = hash_set_add(hs, "str_9", HASH_CODE_FCT_CALL);

    assert_true(hash_set_contains(hs, "str_1", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_2", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_3", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_4", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_5", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_6", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_7", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_8", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_9", HASH_CODE_FCT_CALL), function_node);

    assert_false(hash_set_remove(hs, "not_exists", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_remove(hs, "str_1", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_remove(hs, "str_8", HASH_CODE_FCT_CALL), function_node);

    assert_false(hash_set_contains(hs, "str_1", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_2", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_3", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_4", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_5", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_6", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_7", HASH_CODE_FCT_CALL), function_node);
    assert_false(hash_set_contains(hs, "str_8", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_set_contains(hs, "str_9", HASH_CODE_FCT_CALL), function_node);

    hash_set_destroy(hs);
}
