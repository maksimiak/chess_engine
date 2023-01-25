#include "definitions.h"

std::array<int, BOARD_SIZE> sq120to_sq64;
std::array<int, 64> sq64to_sq120;

void init_sq120_tosq64()
{
    int square = A1;
    int square_64 = 0;

    for (int index = 0; index < BOARD_SIZE; ++index)
    {
        sq120to_sq64[index] = 65;
    }

    for (int index = 0; index < 64; ++index)
    {
        sq64to_sq120[index] = 120;
    }

    for (int rank = RANK_1; rank <= RANK_8; ++rank)
    {
        for (int file = FILE_A; file <= FILE_H; ++file)
        {
            square = FR2SQ(file, rank);
            sq64to_sq120[square_64] = square;
            sq120to_sq64[square] = square_64;
            square_64++;
        }
    }

}
void initialize()
{
    init_sq120_tosq64();
}



