all: dir.c
	gcc -o a.out dir.c

run:
	./a.out $(args)
