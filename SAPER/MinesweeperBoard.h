#include <iostream>
#include <cmath>
struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};
enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};

class MinesweeperBoard
{
public:
    // MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

private:
    Field data[100][100];
    int width;
    int height;

    void setMinesRandomly(int numberOfMines);
    void setDebugMines();
};
