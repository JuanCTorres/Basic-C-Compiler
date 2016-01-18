CC = gcc
CFLAGS = -g
BISONFL = -d -v
FLEXFLAGS = -ll

.PHONY: clean

.SUFFIXES: .c

.cc.o:
	$(CC) $(CFLAGS) -c $<

tree : lex.yy.o tree.tab.o ast.o tree_main.o
	$(CC) -o $@ $(CFLAGS) lex.yy.o tree.tab.o ast.o tree_main.o $(FLEXFLAGS)

lex.yy.o : lex.yy.c
	$(CC) -c $(CFLAGS) $<

tree.tab.o : tree.tab.c
	$(CC) -c $(CFLAGS) $<

lex.yy.c : tree.l tree.tab.h
	flex tree.l

tree.tab.h : tree.y
	bison $(BISONFL) $<

tree.tab.c : tree.y
	bison $(BISONFL) $<

tree_main.o : tree_main.c

clean :
	rm -f tree lex.yy.o tree.tab.o tree_main.o ast.o \
	tree.tab.h tree.tab.c lex.yy.c *~ tree.output

depend :
	makedepend -- $(CFLAGS) -- tree_main.c

# DO NOT DELETE THIS LINE -- make depend depends on it.
