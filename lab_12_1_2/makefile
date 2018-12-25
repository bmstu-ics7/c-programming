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

lib%.a: %.o
	ar rc $@ $^
	ranlib $@

%.dll: %.o
	$(CC) -shared $^ -o $@

static_test.exe: assert.o liblab_07.a test.o
	$(CC) -o $@ $^

dynamic_link_test.exe: assert.o lab_07.dll test.o
	$(CC) -o $@ $^

dynamic_load_test.exe: assert.o load_test.o
	make lab_07.dll
	$(CC) -o $@ $^

clean:
	$(RM) *.o *.exe *.gch *.a *.dll

