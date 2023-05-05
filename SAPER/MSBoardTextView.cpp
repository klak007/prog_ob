// #ifndef MSBOARDTEXTVIEW_H__
// #define MSBOARDTEXTVIEW_H__

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

// class MSBoardTextView
// {
// private:
//     MinesweeperBoard &board;

// public:
//     MSBoardTextView(MinesweeperBoard &board);
//     void display() const;
// };

// #endif

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
