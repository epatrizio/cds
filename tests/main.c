#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests_vector.h"
#include "tests_stack.h"

int main(int argc, char *argv[])
{
    TestSuite *ts_vector = createTestSuite("VECTOR");
    addTestFunction(ts_vector, "int_vector", test_int_vector);
    runTestSuite(ts_vector, argc, argv);
    displayTestSuite(ts_vector);
    deleteTestSuite(ts_vector);

    TestSuite *ts_stack = createTestSuite("STACK");
    addTestFunction(ts_stack, "int_stack", test_int_stack);
    runTestSuite(ts_stack, argc, argv);
    displayTestSuite(ts_stack);
    deleteTestSuite(ts_stack);

    return EXIT_SUCCESS;
}