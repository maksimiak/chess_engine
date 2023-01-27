#include "PrinterUtility.h"
#include "../definitions.h"
#include <iostream>

PrinterUtility::PrinterUtility(U64 bitboard)
    :   m_bitboard(bitboard)
    ,   m_set_mask()
    ,   m_clear_mask()
    ,   m_shifter(1ULL)
{
    m_set_mask.fill(0ULL);
    m_clear_mask.fill(0ULL);
    fill_masks();

}

PrinterUtility::~PrinterUtility()
{
    //dtor
}

void PrinterUtility::set_bitboard(U64 bitboard)
{
    m_bitboard = bitboard;
}
void PrinterUtility::print_bitboard()
{
    int square;
    int square_64;

    for (int rank = RANK_8; rank >= RANK_1; --rank)
    {
        for (int file = FILE_A; file <= FILE_H; ++file)
        {
            square = FR2SQ(file, rank);
            square_64 = SQ64(square);

            if ((m_shifter << square_64) & m_bitboard)
            {
                std::cout << "+";
            }
            else
            {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}
void PrinterUtility::set_square(int square)
{
    m_bitboard |= (m_shifter << SQ64(square));
}
int PrinterUtility::count_bits()
{
    int r;
    U64 temp_bitboard = m_bitboard;
    for (r = 0; temp_bitboard; r++, temp_bitboard &= temp_bitboard - 1);
    return r;
}
int PrinterUtility::pop_bit()
{
    U64 b = m_bitboard ^ (m_bitboard - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    m_bitboard &= (m_bitboard - 1);
    return BIT_BOARD[(fold * 0x783a9b23) >> 26];
}
void PrinterUtility::fill_masks()
{
    for (int index = 0; index < 64; index++)
    {
        m_set_mask[index] |= (m_shifter << index);
        m_clear_mask[index] = !m_set_mask[index];
    }
}
void PrinterUtility::set_bit(int bit)
{
    m_bitboard |= m_set_mask[bit];
}
void PrinterUtility::clear_bit(int bit)
{
    m_bitboard &= m_clear_mask[bit];
}
