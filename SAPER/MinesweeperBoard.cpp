#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode)
{
    width = w;
    height = h;
    gameState = RUNNING;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j].hasMine = false;
            data[i][j].isRevealed = false;
            data[i][j].hasFlag = false;
        }
    }
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
}

void MinesweeperBoard::setMinesRandomly(int numberOfMines)
{
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
    for (int i = 0; i < height && i < width; ++i)
    {
        data[i][i].hasMine = true;
    }

    for (int i = 0; i < width; ++i)
    {
        data[0][i].hasMine = true;
    }

    for (int i = 1; i < height; i += 2)
    {
        data[i][0].hasMine = true;
    }
    data[3][3].hasFlag = true;
    data[5][0].hasFlag = true;
}

void MinesweeperBoard::debug_display() const
{

    std::cout << " ";
    for (int i = 0; i < width; i++)
    {
        std::cout << "    " << i;
    }
    std::cout << std::endl;

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
        std::cout << std::endl;
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
    if (row < 0 || row >= height || col < 0 || col >= width)
    {
        return false;
    }

    if (data[row][col].isRevealed)
    {
        return false;
    }

    if (data[row][col].hasFlag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (gameState != RUNNING)
    {
        return;
    }

    if (row < 0 || row >= height || col < 0 || col >= width)
    {
        return;
    }

    Field &field = data[row][col];
    if (field.isRevealed)
    {
        return;
    }

    field.hasFlag = !field.hasFlag;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (gameState != RUNNING)
        return;

    if (row < 0 || row >= height || col < 0 || col >= width)
        return;

    if (data[row][col].isRevealed)
        return;

    if (data[row][col].hasFlag)
        return;

    if (firstMove)
    {
        if (data[row][col].hasMine)
        {
            setMinesRandomly(1);
            if (data[row][col].hasMine)
                data[row][col].hasMine = false;
            else
                mineCount++;
        }
        firstMove = false;
    }

    data[row][col].isRevealed = true;
    if (data[row][col].hasMine)
    {
        gameState = FINISHED_LOSS;
        return;
    }

    int unrevealedCount = 0;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (!data[i][j].isRevealed && !data[i][j].hasMine)
            {
                unrevealedCount++;
            }
        }
    }

    if (unrevealedCount == mineCount)
    {
        gameState = FINISHED_WIN;
        return;
    }

    if (countMinesAround(row, col) == 0)
    {
        for (int i = row - 1; i <= row + 1; ++i)
        {
            for (int j = col - 1; j <= col + 1; ++j)
            {
                if (i >= 0 && i < height && j >= 0 && j < width && !(i == row && j == col))
                {
                    revealField(i, j);
                }
            }
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (row < 0 || row >= height || col < 0 || col >= width)
    {
        return false;
    }

    return data[row][col].isRevealed;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (row < 0 || row >= height || col < 0 || col >= width)
    {
        return '#';
    }
    else if (!data[row][col].isRevealed && data[row][col].hasFlag)
    {
        return 'F';
    }
    else if (!data[row][col].isRevealed && !data[row][col].hasFlag)
    {
        return '_';
    }
    else if (data[row][col].isRevealed && data[row][col].hasMine)
    {
        return 'x';
    }
    else
    {
        int mines = countMinesAround(row, col);
        if (mines == 0)
        {
            return ' ';
        }
        else
        {
            return mines + '0';
        }
    }
}

GameState MinesweeperBoard::getGameState() const
{

    bool allMinesRevealed = true;
    bool anyNonMineFieldUnrevealed = false;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            const Field &field = data[row][col];
            if (field.hasMine && !field.isRevealed)
            {
                allMinesRevealed = false;
            }
            else if (!field.hasMine && !field.isRevealed)
            {
                anyNonMineFieldUnrevealed = true;
            }
            else if (field.hasMine && field.isRevealed)
            {
                return FINISHED_LOSS;
            }
        }
    }
    if (allMinesRevealed || !anyNonMineFieldUnrevealed)
    {
        return FINISHED_WIN;
    }
    else
    {
        return RUNNING;
    }
}
