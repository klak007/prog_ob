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
    board.toggleFlag(5, 3);

    std::cout << "mines around (0,3): " << board.countMinesAround(0, 3) << std::endl;
    std::cout << "board height: " << board.getBoardHeight() << std::endl;
    std::cout << "board width: " << board.getBoardWidth() << std::endl;
    std::cout << "number of mines on board: " << board.getMineCount() << std::endl;
    std::cout << "if flagged on 3,3: " << board.hasFlag(3, 3) << std::endl;
    GameState state = board.getGameState();
    if (state == RUNNING)
    {
        std::cout << "Game is still running\n";
    }
    else if (state == FINISHED_LOSS)
    {
        std::cout << "You lost the game\n";
    }
    else if (state == FINISHED_WIN)
    {
        std::cout << "You won the game\n";
    }

    return 0;
    board.debug_display();
    return 0;
}
