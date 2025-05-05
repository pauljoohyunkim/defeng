CC=gcc
CFLAGS=-g -Wall
BIN=defeng
SRCDIR=src
BINDIR=bin
OBJDIR=obj

$(BINDIR)/$(BIN): $(OBJDIR)/cluster.o $(OBJDIR)/defeng.o $(OBJDIR)/generator.o $(OBJDIR)/tree.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(BINDIR)/*
	$(RM) -rf $(OBJDIR)/*