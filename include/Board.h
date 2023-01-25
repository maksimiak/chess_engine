#pragma once

#include <array>
#include "Undo.h"
#include "../definitions.h"

class Board
{
    public:
        Board();
        virtual ~Board();

    protected:

    private:
        std::array<int, BOARD_SIZE> m_board;
        std::array<U64, 3> m_pawns;
        std::array<int, 2> m_king_square;
        std::array<int, 13> m_piece_num;
        std::array<int, 3> m_big_pieces;
        std::array<int, 3> m_major_pieces;
        std::array<int, 3> m_minor_pieces;
        std::array<Undo, MAX_MOVES> m_history;
        std::array<std::array<int, 13>, 10> m_piece_list;

        int m_side;
        int m_en_pas;
        int m_fifty_move;
        int m_ply;
        int m_his_ply;
        int m_castle_permission;

        U64 m_pos_key;
};
