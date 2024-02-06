#pragma once
#include "GoBangGameDlg.h"
class ChessBoard
{
public:
    static const int BOARD_SIZE = 15; // ∆Â≈Ã¥Û–°

private:
    int board[BOARD_SIZE][BOARD_SIZE]; // ¥Ê¥¢∆Â≈Ã◊¥Ã¨

public:
    ChessBoard();

   // Player GetPieceAt(int x, int y);
    bool PlacePiece(int x, int y);
    bool IsGameOver(CPoint x, CPoint y);

};

