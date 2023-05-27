#include <iostream>
#include <string>
#include <sstream>

#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view)
    : board(board), view(view)
{
}
void MSTextController::play()
{
    std::cout << "Welcome to Minesweeper!" << std::endl;
    std::cout << "Enter row and column to reveal the field, or 'f' and row and column to toggle flag. for example: input 2,2 will result in revealing 2,2 field. f 2,2 will result in flagging 2,2 field. " << std::endl;

    while (board.getGameState() == GameState::RUNNING)
    {
        view.display();

        std::string input;
        std::getline(std::cin, input);

        int row = -1;
        int col = -1;
        bool flag = false;

        if (input.length() == 5 && (input[0] == 'f' || input[0] == 'F') && input[1] == ' ')
        {
            flag = true;
            row = input[2] - '0';
            col = input[4] - '0';
        }
        else if (input.length() == 3 && input[1] == ',')
        {
            row = input[0] - '0';
            col = input[2] - '0';
        }

        if (row >= 0 && col >= 0)
        {
            if (flag)
            {
                board.toggleFlag(row, col);
            }
            else
            {
                board.revealField(row, col);
            }
        }
        else
        {
            std::cout << "Invalid input, try again!" << std::endl;
        }
    }

    view.display();

    if (board.getGameState() == GameState::FINISHED_WIN)
    {
        std::cout << "Congratulations, you won!" << std::endl;
    }
    else if (board.getGameState() == GameState::FINISHED_LOSS)
    {
        std::cout << "Sorry, you lost. Better luck next time!" << std::endl;
    }
}
