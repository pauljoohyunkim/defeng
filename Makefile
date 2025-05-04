CC=gcc
CFLAGS=-g -Wall
BIN=defeng
SRCDIR=src
BINDIR=bin
OBJDIR=obj

$(BINDIR)/$(BIN): $(SRCDIR)/*
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(BINDIR)/*
	rm $(OBJDIR)/*