#pragma once
#include "../definitions.h"

const std::array<int, 64> BIT_BOARD =
{
    63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
    51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
    26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
    58, 20, 37, 17, 36, 8
};

class PrinterUtility
{
public:
    PrinterUtility(U64 bitboard = 0ULL);
    virtual ~PrinterUtility();
    void set_bitboard(U64 bitboard);
    void print_bitboard();
    void set_square(int square);
    void set_bit(int bit);
    void clear_bit(int bit);
    int count_bits();
    int pop_bit();

protected:

private:

    void fill_masks();

    U64 m_bitboard;
    std::array<U64, 64> m_set_mask;
    std::array<U64, 64> m_clear_mask;
    U64 m_shifter = 1ULL;
};
