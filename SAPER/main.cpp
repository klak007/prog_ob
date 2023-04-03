#include "MinesweeperBoard.h"

int main()
{
    MinesweeperBoard board(9, 7, DEBUG);

    board.toggleFlag(1, 1);
    board.revealField(1, 2);
    std::cout << "mines around (0,3): " << board.countMinesAround(0, 3) << std::endl;
    std::cout << "board height: " << board.getBoardHeight() << std::endl;
    std::cout << "board width: " << board.getBoardWidth() << std::endl;
    std::cout << "number of mines on board: " << board.getMineCount() << std::endl;
    std::cout << "if flagged on 3,3: " << board.hasFlag(3, 3) << std::endl;
    std::cout << "if revealed on 3,3: " << board.isRevealed(3, 3) << std::endl;

    board.debug_display();
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
}
