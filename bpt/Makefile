
CC = gcc

OBJS = bpt_insert.o bpt_delete.o bpt_find.o bpt_util.o bpt_print.o

RM = del

all: bpt_test

bpt_test: test.c $(OBJS)
	$(CC) -Wall $+ -o $@

.c.o:
	$(CC) $(CFLAGS) -Wall -c $<

clean:
	$(RM) -f bpt_test *.o *.dot *.exe
