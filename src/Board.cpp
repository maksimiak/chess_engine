#include "Board.h"

Board::Board()
{
    //ctor
}

Board::~Board()
{
    //dtor
}
std::array<int, BOARD_SIZE> Board::get_board()
{
    return m_board;
}
int Board::get_en_pas()
{
    return m_en_pas;
}
int Board::get_castle_permission()
{
    return m_castle_permission;
}
int Board::get_side()
{
    return m_side;
}
