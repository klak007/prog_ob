#ifndef MINESBOARD_H__
#define MINESBOARD_H__

#include <iostream>
#include <cmath>
enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};
enum GameState
{
    RUNNING,
    FINISHED_WIN,
    FINISHED_LOSS
};

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
private:
    Field data[100][100];
    int width;
    int height;
    int mineCount;

public:
    // MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;

    void setMinesRandomly(int numberOfMines);
    // void setMinesRandomly(GameMode mode);
    void setDebugMines();
};

#endif
