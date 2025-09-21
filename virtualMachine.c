#include<stdio.h>
#include<stdbool.h>
#include "virtualMachine.h"

void init_vm(VM *vm, const int *program, int program_size){
    for(int i=0;i<NUM_OF_REGISTERS;i++){
        vm->registers[i] = 0;
    }
    vm->registers[SP] = -1;

    for(int i=0; i<program_size; i++){
        vm->program[i] = program[i];
    }

    vm->running = true;
}

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int fetch(VM *vm) {
    return vm->program[vm->registers[IP]++];
}

bool underflow(VM *vm){
    if (vm->registers[SP] < 0) {
        printf("Stack underflow!\n");
        vm->running = false;
        return true;
    }
    return false;
}

bool overflow(VM *vm){
    if (vm->registers[SP] >= 255) {
        printf("Stack overflow!\n");
        vm->running = false;
        return true;
    }
    return false;
}

bool validRegister(VM *vm, int reg){
    if(reg < 0 || reg >= NUM_OF_REGISTERS){
        printf("Invalid register %d\n", reg);
        vm->running = false;
        return false;
    }
    return true;
}

void eval(VM *vm, int instr) {
    switch (instr) {
        case HLT:{
            vm->running = false;
            break;
        }
        case PSH: {
            if(overflow(vm)) break;
            vm->stack[++vm->registers[SP]] = fetch(vm);
            break;
        }
        case POP: {
            if (underflow(vm)) break;
            printf("Popped %d\n",vm->stack[vm->registers[SP]--]);
            break;
        }
        case ADD: {
            if (vm->registers[SP] < 1) {
                printf("Stack underflow on ADD!\n");
                vm->running = false;
                break;
            }
            int a = vm->stack[vm->registers[SP]--];
            int b = vm->stack[vm->registers[SP]--];

            int result = b+a;
            vm->stack[++vm->registers[SP]] = result;
            break;
        }
        case SET: {
            int reg = fetch(vm);
            int pos = fetch(vm);
            if(validRegister(vm, reg)) vm->registers[reg] = pos;
            break;
        }
        default:
            break;
    }
};

void run(VM *vm){
    while(vm->running){
        eval(vm, fetch(vm));
    }
}

int main(){
    VM vm1;
    init_vm(&vm1, program, sizeof(program)/sizeof(program[0]));
    run(&vm1);
    return 0;
}