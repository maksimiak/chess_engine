#pragma once

#define NAME "Chess Engine"
#define BOARD_SIZE 120
#define MAX_MOVES 2048
// #define NDEBUG // for assertions

#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) )
#define SQ64(sq120) sq120to_sq64[sq120]

#include <array>
#include <cassert>




extern std::array<int, BOARD_SIZE> sq120to_sq64;
extern std::array<int, 64> sq64to_sq120;

extern void initialize();

typedef unsigned long long U64;

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8 };
enum { WHITE, BLACK, BOTH};

enum
{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

