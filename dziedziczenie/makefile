CC = g++
CFLAGS = -std=c++11 -Wall

parkowanie: pojazd.o parking.o main.o
	$(CC) $(CFLAGS) -o parkowanie pojazd.o parking.o main.o

pojazd.o: pojazd.cpp pojazd.h
	$(CC) $(CFLAGS) -c pojazd.cpp


parking.o: parking.cpp parking.h
	$(CC) $(CFLAGS) -c parking.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f parkowanie pojazd.o parking.o main.o
