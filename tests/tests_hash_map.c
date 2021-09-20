#include <stdio.h>
#include <stdlib.h>

#include "tests_utils.h"
#include "tests_hash_map.h"

void test_hash_map(const void *function_node)
{
    hash_map hm = hash_map_create(2);

    assert_false(hash_map_contains(hm, "key_not_exists", HASH_CODE_FCT_CALL), function_node);

    hm = hash_map_add(hm, "key_1", "str_1", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_2", "str_2", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_3", "str_3", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_4", "str_4", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_5", "str_5", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_6", "str_6", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_7", "str_7", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_8", "str_8", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_9", "str_9", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_9", "str_9", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_10", "str_10", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_11", "str_11", HASH_CODE_FCT_CALL);
    hm = hash_map_add(hm, "key_12", "str_12", HASH_CODE_FCT_CALL);

    assert_true(hash_map_contains(hm, "key_1", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_2", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_3", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_4", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_5", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_6", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_7", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_8", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_9", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_10", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_11", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_12", HASH_CODE_FCT_CALL), function_node);

    assert_equals_charp("str_1", hash_map_get(hm, "key_1", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_2", hash_map_get(hm, "key_2", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_3", hash_map_get(hm, "key_3", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_4", hash_map_get(hm, "key_4", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_5", hash_map_get(hm, "key_5", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_6", hash_map_get(hm, "key_6", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_7", hash_map_get(hm, "key_7", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_8", hash_map_get(hm, "key_8", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_9", hash_map_get(hm, "key_9", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_10", hash_map_get(hm, "key_10", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_11", hash_map_get(hm, "key_11", HASH_CODE_FCT_CALL), function_node);
    assert_equals_charp("str_12", hash_map_get(hm, "key_12", HASH_CODE_FCT_CALL), function_node);

    hm = hash_map_add(hm, "key_8", "str_88", HASH_CODE_FCT_CALL);
    assert_equals_charp("str_88", hash_map_get(hm, "key_8", HASH_CODE_FCT_CALL), function_node);

    assert_false(hash_map_remove(hm, "key_not_exists", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_remove(hm, "key_1", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_remove(hm, "key_2", HASH_CODE_FCT_CALL), function_node);

    assert_false(hash_map_contains(hm, "key_1", HASH_CODE_FCT_CALL), function_node);
    assert_false(hash_map_contains(hm, "key_2", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_3", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_4", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_5", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_6", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_7", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_8", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_9", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_10", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_11", HASH_CODE_FCT_CALL), function_node);
    assert_true(hash_map_contains(hm, "key_12", HASH_CODE_FCT_CALL), function_node);

    assert_null(hash_map_get(hm, "key_not_exists", HASH_CODE_FCT_CALL), function_node);
    assert_null(hash_map_get(hm, "key_1", HASH_CODE_FCT_CALL), function_node);
    assert_null(hash_map_get(hm, "key_2", HASH_CODE_FCT_CALL), function_node);

    hash_map_destroy(hm);
}
