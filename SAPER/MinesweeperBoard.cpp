#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode)
{
    width = w;
    height = h;
    gameState = RUNNING;
    // set all places to 0
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j].hasMine = false;
            data[i][j].isRevealed = false;
            data[i][j].hasFlag = false;
        }
    }
    // how many mines in each of gamemodes
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

    /*// mine (row=0, column=0)
    data[0][0].hasMine = true;
    data[0][0].isRevealed = false;
    data[0][0].hasFlag = false;

    // revealed (row=1, column=1)
    data[1][1].hasMine = false;
    data[1][1].isRevealed = true;
    data[1][1].hasFlag = false;

    // mine flagged (row=0, column=2)
    data[0][2].hasMine = true;
    data[0][2].isRevealed = false;
    data[0][2].hasFlag = true;*/
}

void MinesweeperBoard::setMinesRandomly(int numberOfMines)
{
    // randomly set all the mines on the board
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
    // numbers of columns
    std::cout << " ";
    for (int i = 0; i < width; i++)
    {
        std::cout << "    " << i;
    }
    std::cout << std::endl;

    // drawing the board
    for (int i = 0; i < height; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < width; j++)
        {
            std::string output = "[";
            if (data[i][j].hasMine)
            {
                output += "M"; // if place has Mine, write M
            }
            else
            {
                output += "."; // if not write .
            }
            if (data[i][j].isRevealed)
            {
                output += "o"; // if place is revealed place o
            }
            else
            {
                output += "."; // if not write .
            }
            if (data[i][j].hasFlag)
            {
                output += "f"; // if place is flagged, write f
            }
            else
            {
                output += "."; // if not write .
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
    if (row < 0 || row >= height || col < 0 || col >= width) // chech if (row, col) is within board
    {
        return false;
    }

    if (data[row][col].isRevealed) // chech if place revealed
    {
        return false;
    }

    if (data[row][col].hasFlag) // check if place has the flag
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
    // Check if game is already finished
    if (gameState != RUNNING)
        return;

    // Check if field is outside board
    if (row < 0 || row >= height || col < 0 || col >= width)
        return;

    // Check if field was already revealed
    if (data[row][col].isRevealed)
        return;

    // Check if there is a flag on the field
    if (data[row][col].hasFlag)
        return;

    // If it's the first player action, move mine if necessary
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

    // Reveal the field
    data[row][col].isRevealed = true;
    if (data[row][col].hasMine)
    {
        gameState = FINISHED_LOSS;
        return;
    }

    // Check if player won the game
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

    // If there are no mines around, reveal neighboring fields recursively
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
        // field is outside of the board
        return false;
    }

    return data[row][col].isRevealed;
}

GameState MinesweeperBoard::getGameState() const
{
    // Check if game is finished (either win or loss)
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
