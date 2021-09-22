compile:
	gcc -c -Wall -Wextra src/vector.c src/stack.c src/linked_list.c src/queue.c								\
	src/hash_utils.c src/hash_set.c src/hash_map.c

compile_test:
	gcc -g -o cds_test -Wall -Wextra																		\
	src/vector.c src/stack.c src/linked_list.c src/queue.c src/hash_utils.c src/hash_set.c src/hash_map.c	\
	tests/tests_vector.c tests/tests_stack.c tests/tests_linked_list.c tests/tests_queue.c					\
	tests/tests_utils.c tests/tests_hash_set.c tests/tests_hash_map.c tests/main.c							\
	-lm -L./tests/lib -lctestfmk

compile_example:
	gcc -g -o intl -Wall -Wextra	\
	src/vector.c src/hash_utils.c src/hash_map.c example/intl.c example/main.c