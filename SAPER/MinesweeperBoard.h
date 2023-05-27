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
    bool firstMove = 1;
    GameState gameState;

public:
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
    void setMinesRandomly(int numberOfMines);
    void setDebugMines();

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;

    int countMinesAround(int row, int col) const;

    bool hasFlag(int row, int col) const;
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    void toggleFlag(int row, int col);

    char getFieldInfo(int row, int col) const;

    GameState getGameState() const;
};

#endif
