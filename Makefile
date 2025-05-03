CC=gcc
CFLAGS=-g -Wall
BIN=defeng
SRCDIR=src
BINDIR=bin

$(BIN): $(SRCDIR)/defeng.c
	$(CC) $(CFLAGS) $< -o $@