#include "systemc.h"

SC_MODULE(tristate_buf) {
    sc_in<bool> input;
    sc_in<bool> enable;
    sc_out<sc_logic> output;

    void process() {
        sc_logic out;

        if (enable)
            out = input;
        else
            out = 'z';

        output = out;
    }

    SC_CTOR(tristate_buf) {
        SC_METHOD(process);     // register process to kernel
        sensitive << enable << input;
    }
};
