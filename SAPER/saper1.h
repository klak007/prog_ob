#include <iostream>

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
public:
    MinesweeperBoard();
    void debug_display() const;

private:
    Field data[100][100];
    int width;
    int height;
};

// MinesweeperBoard::MinesweeperBoard()
// {
//     // inicjalizacja planszy o domyślnej szerokości i wysokości
//     width = 10;
//     height = 10;
//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             data[i][j].hasMine = false;
//             data[i][j].hasFlag = false;
//             data[i][j].isRevealed = false;
//         }
//     }
// }

MinesweeperBoard::MinesweeperBoard()
{
    width = 5;
    height = 7;

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

    // Ustaw pole (wiersz=0, kolumna=0)
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
    data[0][2].hasFlag = true;
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