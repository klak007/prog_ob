#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"

class MSBoardTextView
{
private:
    const MinesweeperBoard &board;

public:
    MSBoardTextView(MinesweeperBoard &board);
    void display() const;
};

#endif // MSBOARDTEXTVIEW_H