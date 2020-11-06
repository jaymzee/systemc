//-----------------------------------------------------
// This is my second Systemc Example
// Design Name : first_counter
// File Name : first_counter.cpp
// Function : This is a 4 bit up-counter with
// Synchronous active high reset and
// with active high enable signal
//-----------------------------------------------------
#include "systemc.h"

SC_MODULE(counter4) {
    sc_in_clk           clock ;     // Clock input of the design
    sc_in<bool>         reset ;     // active high, synchronous Reset input
    sc_in<bool>         enable;     // Active high enable signal for counter
    sc_out<sc_bv<4>>    out;        // 4 bit vector output of the counter

    //------------Local Variables Here---------------------
    sc_uint<4>          count;

    //------------Code Starts Here-------------------------
    // Below function implements actual counter logic
    void incr_count () {
        if (reset == 1) {
            count = 0;
        } else if (enable == 1) {
            count = count + 1;
            cout << "@" << sc_time_stamp() << " :: Incremented Counter "
                 << count << endl;
        }
        out = count;
    }

    // Constructor for the counter
    // Since this counter is a positive edge trigged one,
    // We trigger the below block with respect to positive
    // edge of the clock and also whenever reset changes state
    SC_CTOR(counter4) {
        cout << "Executing new counter\n";
        SC_METHOD(incr_count);      // register incr_count to kernel
        sensitive << reset;
        sensitive << clock.pos();
    }
};
