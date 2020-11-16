#include "systemc.h"

int sc_main(int argc, char *argv[])
{
    sc_logic bit;
    sc_uint<8> u8;
    u8 = 0x5a;
    bit = u8[6].to_bool();
    cout << hex << u8 << endl;
    cout << hex << bit << endl;

    sc_uint<4> u4;
    u4 = u8.range(5,2);

    sc_uint<12> i12;
    i12 = (u8, u4);

    cout << hex << i12 << endl;

    return 0;
}
