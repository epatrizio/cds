compile:
	gcc -c -Wall -Wextra src/vector.c src/stack.c src/priority_queue.c src/linked_list.c src/queue.c		\
	src/hash_utils.c src/hash_set.c src/hash_map.c src/graph.c

compile_test:
	gcc -g -o cds_test -Wall -Wextra																						\
	src/vector.c src/stack.c src/priority_queue.c src/linked_list.c src/queue.c src/hash_utils.c							\
	src/hash_set.c src/hash_map.c src/graph.c																				\
	tests/tests_vector.c tests/tests_stack.c tests/tests_priority_queue.c tests/tests_linked_list.c tests/tests_queue.c		\
	tests/tests_utils.c tests/tests_hash_set.c tests/tests_hash_map.c tests/tests_graph.c tests/main.c						\
	-lm -L./tests/lib -lctestfmk

run_test:
	./cds_test

run_test_debug:
	valgrind ./cds_test

compile_example_intl:
	gcc -g -o intl -Wall -Wextra	\
	src/vector.c src/hash_utils.c src/hash_map.c examples/intl/intl.c examples/intl/main.c

compile_example_sort:
	gcc -g -o sort -Wall -Wextra	\
	src/vector.c src/priority_queue.c examples/sort/main.c

compile_example_dot:
	gcc -g -o dot -Wall -Wextra	\
	src/vector.c src/linked_list.c src/queue.c src/hash_utils.c src/hash_set.c src/graph.c examples/dot/main.c

clean:
	rm -rf *.dot *.o cds_test intl sort dot

# Adjust src/*.c list to compile according to the data structures to be used elsewhere
libcds_static:
	mkdir -p lib
	gcc -c -Wall -Wextra -O3 src/vector.c
	mv vector.o lib/vector.o
	cp src/vector.h lib/vector.h
	ar -rc lib/libvector.a lib/*.o
	ranlib lib/libvector.a
	rm lib/*.o