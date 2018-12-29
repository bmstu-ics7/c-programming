KEYS := -std=c99 -Wall -Werror -pedantic
CC := gcc
RM := rm

ifeq ($(mode), debug)
    KEYS += -g3
endif

ifeq ($(mode), release)
    KEYS += -g0
endif

%.o: %.c *.h
	$(CC) $(KEYS) -c $<

test.exe: my_snprintf.o assert.o test.o
	$(CC) -o $@ $^

clean:
	$(RM) *.o *.exe *.gch


