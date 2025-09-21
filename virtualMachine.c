#include<stdio.h>
#include<stdbool.h>

#define STACK_SIZE 256
static int stack[STACK_SIZE];

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

typedef enum {
    A, B, C, D, E, F, IP, SP,
    NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS] = {[IP] = 0, [SP] = -1};
bool running = true;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int fetch() {
    return program[registers[IP]++];
}

bool underflow(){
    if (registers[SP] < 0) {
        printf("Stack underflow!\n");
        running = false;
        return true;
    }
    return false;
}

bool overflow(){
    if (registers[SP] >= 255) {
        printf("Stack overflow!\n");
        running = false;
        return true;
    }
    return false;
}

bool validRegister(int reg){
    if(reg < 0 || reg >= NUM_OF_REGISTERS){
        printf("Invalid register %d\n", reg);
        running = false;
        return false;
    }
    return true;
}

void eval(int instr) {
    switch (instr) {
        case HLT:{
            running = false;
            break;
        }
        case PSH: {
            if(overflow()) break;
            stack[++registers[SP]] = fetch();
            break;
        }
        case POP: {
            if (underflow()) break;
            printf("Popped %d\n",stack[registers[SP]--]);
            break;
        }
        case ADD: {
            if (registers[SP] < 1) {
                printf("Stack underflow on ADD!\n");
                running = false;
                break;
            }
            int a = stack[registers[SP]--];
            int b = stack[registers[SP]--];

            int result = b+a;
            stack[++registers[SP]] = result;
            break;
        }
        case SET: {
            int reg = fetch();
            int pos = fetch();
            if(validRegister(reg)) registers[reg] = pos;
            break;
        }
        default:
            break;
    }
};

int main(){
    while(running){
        eval(fetch());
    }
    return 0;
}