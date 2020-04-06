all:
	bison --yacc --defines --output=parser.c parser.y -v
	flex --outfile=scanner.c scanner.l
	gcc -o parser scanner.c parser.c

.PHONY: run clean

clean:
	rm -rf *.out
	rm -rf *~
	rm -rf *.c
	rm -rf *.output
	rm -rf *.o
