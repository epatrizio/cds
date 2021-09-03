compile:
	gcc -c -Wall -Wextra src/vector.c src/stack.c src/linked_list.c

compile_test:
	gcc -g -o cds_test -Wall -Wextra													\
	src/vector.c src/stack.c src/linked_list.c											\
	tests/tests_vector.c tests/tests_stack.c tests/tests_linked_list.c tests/main.c		\
	-lm -L./tests/lib -lctestfmk
