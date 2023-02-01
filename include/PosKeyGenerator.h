#pragma once

#include "../definitions.h"
#include "Board.h"

class PosKeyGenerator
{
    public:
        PosKeyGenerator();
        virtual ~PosKeyGenerator();

        U64 generate_pos_key(Board* position);

    protected:

    private:
        std::array<std::array<U64, 13>, BOARD_SIZE> m_piece_keys;
        std::array<U64, 16> m_castle_keys;
        U64 m_side_key;

        bool is_valid_position(int piece);
        void initialize_keys();
        U64 random_64();

};

