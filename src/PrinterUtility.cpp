#include "PrinterUtility.h"
#include "../definitions.h"
#include <iostream>

PrinterUtility::PrinterUtility(U64 bitboard)
    :   m_bitboard(bitboard)
    ,   m_shifter(1ULL)
{
    //ctor
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


}
