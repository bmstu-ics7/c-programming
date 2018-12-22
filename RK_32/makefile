KEYS := -std=c99
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

build: weather.o main.o
	$(CC) -o app.exe $^

run: app.exe
	./app.exe -i EKB.csv

clean:
	$(RM) *.o *.exe *.gch *.out

