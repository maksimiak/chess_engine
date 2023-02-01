#include "PosKeyGenerator.h"
#include <random>
#include <cmath>

PosKeyGenerator::PosKeyGenerator()
{
    //ctor
}

PosKeyGenerator::~PosKeyGenerator()
{
    //dtor
}
U64 PosKeyGenerator::generate_pos_key(Board* position)
{
    U64 final_key = 0;
    int piece = EMPTY;

    for (int sq = 0; sq < BOARD_SIZE; ++sq)
    {
        piece = position->get_board()[sq];
        if (is_valid_position(piece))
        {
            assert(piece >= wP && piece <= bK);
            final_key ^=  m_piece_keys[piece][sq];
        }

    }

    if (position->get_side() == WHITE)
    {
        final_key ^= m_side_key;
    }

    if (position->get_en_pas() != NO_SQ)
    {
        assert(position->get_en_pas() >= 0 && position->get_en_pas() < BOARD_SIZE);
        final_key ^= m_piece_keys[EMPTY][position->get_en_pas()];
    }

    assert(position->get_castle_permission() >= 0 && position->get_castle_permission() <= 15);

    final_key ^= m_castle_keys[position->get_castle_permission()];

    return final_key;
}
bool PosKeyGenerator::is_valid_position(int piece)
{
    return piece != NO_SQ && piece != EMPTY;
}
void PosKeyGenerator::initialize_keys()
{
    for (int index = 0; index < 13; ++index)
    {
        for (int in_index = 0; in_index < BOARD_SIZE; ++in_index)
        {
            m_piece_keys[index][in_index] = random_64();
        }
    }
    m_side_key = random_64();
    for (int index = 0; index < 16; ++index)
    {
        m_castle_keys[index] = random_64();
    }
}
U64 PosKeyGenerator::random_64()
{
    std::random_device rd;
    std::mt19937_64 e2(rd());
    std::uniform_int_distribution<U64> dist(std::llround(0), std::llround(std::pow(2,63)));
    return dist(e2);
}
