KEYS := -std=c99 -Wall -Werror
CC := gcc
RM := rm

ifeq ($(mode), debug)
    KEYS += -g3
endif

ifeq ($(mode), release)
    KEYS += -g0
endif

%.o: %.c *.h
	$(CC) $(KEYS) -c $^

app.exe: work_wlist.o main.o
	$(CC) -o app.exe $^

run: app.exe
	./app.exe
	python3 graph.py

ftest: work_wlist.o test.o
	$(CC) -o ftest.exe $^

clean:
	$(RM) *.o *.exe *.gch *.out

