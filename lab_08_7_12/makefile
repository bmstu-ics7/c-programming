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

app.exe: work_memory.o file_matrix.o sum_matrix.o deg_matrix.o operation.o main.o 
	$(CC) -o app.exe $^

test.exe: assert.o test.o
	$(CC) -o test.exe $^

clean:
	$(RM) *.o *.exe *.gch
