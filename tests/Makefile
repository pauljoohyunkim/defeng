CC=gcc
CFLAGS=-g -Wall

all: treegen_test cluster_test output_computation_test generator_test

treegen_test: treegen_test.c ../src/tree.c
	$(CC) $(CFLAGS) $^ -o $@

cluster_test: cluster_test.c ../src/cluster.c
	$(CC) $(CFLAGS) $^ -o $@

output_computation_test: output_computation_test.c ../src/tree.c
	$(CC) $(CFLAGS) $^ -o $@

generator_test: generator_test.c ../src/generator.c ../src/tree.c ../src/cluster.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *_test
