compile:
	gcc -c -Wall -Wextra src/vector.c

compile_test:
	gcc -g -o cds_test -Wall -Wextra src/vector.c tests/tests_vector.c tests/main.c -lm -L./tests/lib -lctestfmk
