#include "MinesweeperBoard.h"

int main()
{
    MinesweeperBoard board(9, 7, DEBUG);
    board.debug_display();
    board.getBoardHeight();
    board.getBoardWidth();
    board.getMineCount();
    board.countMinesAround(1, 0);
    board.hasFlag(1, 0);

    std::cout << "Liczba min dookoła pola (0,3): " << board.countMinesAround(0, 3) << std::endl;
    std::cout << "Wysokość planszy: " << board.getBoardHeight() << std::endl;
    std::cout << "Szerokość planszy: " << board.getBoardWidth() << std::endl;
    std::cout << "Liczba min na planszy: " << board.getMineCount() << std::endl;
    std::cout << "Czy ma flagę na 3,3: " << board.hasFlag(3, 3) << std::endl;
    return 0;
}
