#include "MinesweeperBoard.h"
// MinesweeperBoard::MinesweeperBoard()
// {
//     width = 10;
//     height = 10;
//     setMinesRandomly(10);
// }
MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode)
{
    width = w;
    height = h;

    // Ustaw stan początkowy pól planszy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j].hasMine = false;
            data[i][j].isRevealed = false;
            data[i][j].hasFlag = false;
        }
    }
    // Rozmieszczenie min na planszy w zależności od trybu
    switch (mode)
    {
    case DEBUG:
        setDebugMines();
        break;
    case EASY:
        setMinesRandomly(ceil(width * height * 0.1));
        break;
    case NORMAL:
        setMinesRandomly(ceil(width * height * 0.2));
        break;
    case HARD:
        setMinesRandomly(ceil(width * height * 0.3));
        break;
    }

    /*// Ustaw pole (wiersz=0, kolumna=0)
    data[0][0].hasMine = true;
    data[0][0].isRevealed = false;
    data[0][0].hasFlag = false;

    // Ustaw pole (wiersz=1, kolumna=1)
    data[1][1].hasMine = false;
    data[1][1].isRevealed = true;
    data[1][1].hasFlag = false;

    // Ustaw pole (wiersz=0, kolumna=2)
    data[0][2].hasMine = true;
    data[0][2].isRevealed = false;
    data[0][2].hasFlag = true;*/
}

void MinesweeperBoard::setMinesRandomly(int numberOfMines)
{
    // Rozmieszczenie min na planszy losowo
    for (int i = 0; i < numberOfMines; i++)
    {
        int x, y;
        do
        {
            x = rand() % width;
            y = rand() % height;
        } while (data[y][x].hasMine);
        data[y][x].hasMine = true;
    }
}

void MinesweeperBoard::setDebugMines()
{
    // Place mines on diagonal
    for (int i = 0; i < height && i < width; ++i)
    {
        data[i][i].hasMine = true;
    }

    // Place mines on first row
    for (int i = 0; i < width; ++i)
    {
        data[0][i].hasMine = true;
    }

    // Place mines on every other cell in first column
    for (int i = 1; i < height; i += 2)
    {
        data[i][0].hasMine = true;
    }
    data[3][3].hasFlag = true;
    data[5][0].hasFlag = true;
}

void MinesweeperBoard::debug_display() const
{
    // wypisanie numerów kolumn
    std::cout << " ";
    for (int i = 0; i < width; i++)
    {
        std::cout << "    " << i;
    }
    std::cout << "\n";

    // wypisanie planszy
    for (int i = 0; i < height; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < width; j++)
        {
            std::string output = "[";
            if (data[i][j].hasMine)
            {
                output += "M";
            }
            else
            {
                output += ".";
            }
            if (data[i][j].isRevealed)
            {
                output += "o";
            }
            else
            {
                output += ".";
            }
            if (data[i][j].hasFlag)
            {
                output += "f";
            }
            else
            {
                output += ".";
            }
            output += "]";
            std::cout << output;
        }
        std::cout << "\n";
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    int mineCount = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (data[i][j].hasMine)
            {
                mineCount++;
            }
        }
    }
    return mineCount;
}
int MinesweeperBoard::countMinesAround(int row, int col) const
{
    if (row < 0 || row >= height || col < 0 || col >= width)
    {
        return -1;
    }

    int minesCount = 0;
    for (int r = std::max(row - 1, 0); r <= std::min(row + 1, height - 1); r++)
    {
        for (int c = std::max(col - 1, 0); c <= std::min(col + 1, width - 1); c++)
        {
            if (data[r][c].hasMine && !(r == row && c == col))
            {
                minesCount++;
            }
        }
    }
    return minesCount;
}
bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (row < 0 || row >= height || col < 0 || col >= width) // sprawdź, czy (row, col) znajduje się na planszy
    {
        return false;
    }

    if (data[row][col].isRevealed) // sprawdź, czy pole zostało już odkryte
    {
        return false;
    }

    if (data[row][col].hasFlag) // sprawdź, czy na polu znajduje się flaga
    {
        return true;
    }
    else
    {
        return false;
    }
}
