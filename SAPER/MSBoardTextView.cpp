#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : board(board)
{
}

void MSBoardTextView::display() const
{
    for (int row = 0; row < board.getBoardHeight(); row++)
    {
        for (int col = 0; col < board.getBoardWidth(); col++)
        {
            std::cout << board.getFieldInfo(row, col) << " ";
        }
        std::cout << std::endl;
    }
}
