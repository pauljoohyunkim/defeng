CC=gcc
CFLAGS=-g -Wall

treegen_test: treegen_test.c ../src/tree.c
	$(CC) $(CFLAGS) $^ -o $@

file_test: file_test.c ../src/cluster.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) treegen_test
