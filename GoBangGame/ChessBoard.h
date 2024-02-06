#pragma once
#include "GoBangGameDlg.h"
class ChessBoard
{
public:
    static const int BOARD_SIZE = 15; // ���̴�С

private:
    int board[BOARD_SIZE][BOARD_SIZE]; // �洢����״̬

public:
    ChessBoard();

   // Player GetPieceAt(int x, int y);
    bool PlacePiece(int x, int y);
    bool IsGameOver(CPoint x, CPoint y);

};

