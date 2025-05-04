CC=gcc
CFLAGS=-g -Wall

treegen_test: treegen_test.c ../src/tree.c
	$(CC) $(CFLAGS) $^ -o $@

cluster_test: cluster_test.c ../src/cluster.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *_test
