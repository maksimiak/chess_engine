#include <iostream>
#include "definitions.h"
#include "PrinterUtility.h"

int main()
{
    initialize();

    U64 play_board = 0ULL;
    PrinterUtility printer(play_board);
    printer.print_bitboard();
    std::cout << std::endl;
    printer.set_square(A1);
    printer.set_square(A2);
    printer.set_square(A3);
    printer.print_bitboard();
    std::cout << std::endl;
    std::cout << printer.count_bits();





    return 0;
}
