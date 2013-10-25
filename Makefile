

CC=gcc
CFLAGS=-s

.SUFFIXES: .c .o

ALL = fifo_list
all: $(ALL)

OBJ=	fifo_list.o\
	test_main.o

fifo_list: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 
	
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $*.c
	
.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f $(ALL)
	
