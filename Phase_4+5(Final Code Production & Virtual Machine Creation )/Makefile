all: compiler VM exec

exec:
	./avm binary.bin

compiler:
	bison --yacc --defines --output=parser.c parser.y -v
	flex --outfile=scanner.c scanner.l
	gcc -o parser scanner.c parser.c

VM:
	gcc -o avm VirtualMachine.c -lm

.PHONY: run clean
	
clean:
	rm lex.yy.*
	rm parser.c
	rm parser.h
	rm parser.o
