#include "../include/virtualMachine.h"

const int program[] = {
    PSH, 6,
    PSH, 6,
    ADD,
    POP,
    HLT
};


int main(){
    VM vm1;
    init_vm(&vm1, program, sizeof(program)/sizeof(program[0]));
    run(&vm1);
    return 0;
}