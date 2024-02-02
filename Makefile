CC=gcc
CFLAGS=-c -Wall -I. -fpic -g -fbounds-check
CFLAGS=-c -Wall -I. -fpic -g -fbounds-check -Werror

OBJS=test.o Project0.o

%.o:	%.c %.h
	$(CC) $(CFLAGS) $< -o $@

test:	$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:	
	rm -f Project0.o test.o test