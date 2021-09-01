#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests_vector.h"

int main(int argc, char *argv[])
{
    TestSuite *ts_vector = createTestSuite("VECTOR");
    addTestFunction(ts_vector, "int_vector", test_int_vector);
    runTestSuite(ts_vector, argc, argv);

    displayTestSuite(ts_vector);
    deleteTestSuite(ts_vector);

    return EXIT_SUCCESS;
}