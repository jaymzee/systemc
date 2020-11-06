#include "systemc.h"

SC_MODULE(hello_world) {                //module (class) declaration
    SC_CTOR(hello_world) {              // constructor
        // empty constructor
    }
    void say_hello() {                  // process
        cout << "Hello World!\n";
    }
};

int sc_main(int argc, char *argv[]) {
    hello_world hello("HELLO");
    hello.say_hello();
    return 0;
}
