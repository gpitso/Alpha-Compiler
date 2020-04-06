CC=gcc
FLEX=flex
FFLAGS= --outfile
OFLAGS=-o
REM=rm -f

all: al.c
	$(CC) $(OFLAGS) al al.c 

al.c: al.l
	$(FLEX) $(FFLAGS)=al.c al.l

clean:
	$(REM) al
