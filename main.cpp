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
    printer.set_square(D2);
    printer.set_square(D3);
    printer.set_square(D4);
    printer.print_bitboard();
    std::cout << std::endl;
    // std::cout << printer.count_bits() << std::endl;
    std::cout << printer.pop_bit() << std::endl;
    printer.print_bitboard();
    std::cout << std::endl;
    //std::cout << printer.count_bits();




    return 0;
}
