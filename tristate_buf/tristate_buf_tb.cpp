#include "systemc.h"
#include "tristate_buf.cpp"

int sc_main(int argc, char *argv[])
{
    sc_signal<bool> enable;
    sc_signal<bool> input;
    sc_signal<sc_logic> output;

    tristate_buf u1("TRISTATE_BUF");
        u1.enable(enable);
        u1.input(input);
        u1.output(output);

    sc_start(0, SC_NS);

    sc_trace_file *wf = sc_create_vcd_trace_file("tristate_buf");
    sc_trace(wf, enable, "enable");
    sc_trace(wf, input, "input");
    sc_trace(wf, output, "output");

    input = 0;
    enable = 0;
    sc_start(1, SC_NS);

    enable = 1;
    sc_start(1, SC_NS);

    input = 1;
    sc_start(1, SC_NS);

    enable = 0;
    sc_start(1, SC_NS);

    input = 0;
    sc_start(1, SC_NS);

    return 0;
}
