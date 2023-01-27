#include <iostream>
#include "definitions.h"
#include "PrinterUtility.h"

int main()
{
    initialize();

    U64 play_board = 0ULL;
    PrinterUtility printer(play_board);
    printer.print_bitboard();
    std::cout<<std::endl;
    printer.set_bit(62);
    printer.print_bitboard();
    std::cout<<std::endl;
    printer.clear_bit(62);
    printer.print_bitboard();
    std::cout<<std::endl;





    return 0;
}
