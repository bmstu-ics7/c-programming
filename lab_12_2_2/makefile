KEYS := -std=c99 -Wall -Werror
CC := gcc
RM := rm
DKEYS := -L. -larr -o

ifeq ($(mode), debug)
    KEYS += -g3
endif

ifeq ($(mode), release)
    KEYS += -g0
endif

%.o: %.c %.h
	$(CC) $(KEYS) -c $^

%.dll: %.o
	$(CC) -shared $^ -o $@

clean:
	$(RM) *.o *.exe *.gch *.a *.dll

