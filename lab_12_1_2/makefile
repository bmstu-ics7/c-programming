KEYS := -std=c99 -Wall -Werror
CC := gcc
RM := rm

ifeq ($(mode), debug)
    KEYS += -g3
endif

ifeq ($(mode), release)
    KEYS += -g0
endif

%.o: %.c %.h
	$(CC) $(KEYS) -c $^

lib%.a: %.o
	ar rc $@ $^
	ranlib $@

test.exe: assert.o liblab_07.a test.o
	$(CC) -o $@ $^

clean:
	$(RM) *.o *.exe *.gch *.a *.dll

