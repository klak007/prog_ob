# CC = g++
# CFLAGS = -Wall -Wextra -pedantic -std=c++11

# saper: MinesweeperBoard.cpp MinesweeperBoard.h main.cpp
# 	$(CC) $(CFLAGS) MinesweeperBoard.cpp main.cpp -o saper
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

all: saper

saper: MinesweeperBoard.cpp MinesweeperBoard.h MSTextController.cpp MSTextController.h MSBoardTextView.cpp MSBoardTextView.h main.cpp
	$(CC) $(CFLAGS) MinesweeperBoard.cpp MSTextController.cpp MSBoardTextView.cpp main.cpp -o saper

clean:
	rm -f saper
