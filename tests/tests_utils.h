#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#define HASH_CODE_FCT_CALL (size_t (*)(const char*))(hash_code)

size_t hash_code(const char*);

#endif