#include "pch.h"
#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
    // ��ʼ�����̣�������λ�ö�����Ϊ��
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
        return false; // λ����Ч����������
    }

    board[x][y] = BLACK;

    return true;
}

bool ChessBoard::IsGameOver(CPoint x, CPoint y)
{
    // ������ʵ���ж���Ϸ�Ƿ�������߼��������ж��Ƿ�����������
    // �������Ĺ�����ʵ���������

    return true;
}