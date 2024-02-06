#include "pch.h"
#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
    // 初始化棋盘，将所有位置都设置为空
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            board[x][y] = (0,0);
        }
    }
}

//ChessBoard::Player ChessBoard::GetPieceAt(int x, int y)
//{
//    return board[x][y];
//}

bool ChessBoard::PlacePiece(int x, int y)
{
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE|| board[x][y] != EMPTY)
    {
        return false; // 位置无效或已有棋子
    }

    board[x][y] = BLACK;

    return true;
}

bool ChessBoard::IsGameOver(CPoint x, CPoint y)
{
    // 在这里实现判断游戏是否结束的逻辑，例如判断是否有五子连珠
    // 根据您的规则来实现这个方法

    return true;
}