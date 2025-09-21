#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdbool.h>

#define STACK_SIZE 256
#define PROGRAM_SIZE 256

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

typedef struct {
    int stack[STACK_SIZE];
    int registers[NUM_OF_REGISTERS];
    int program[PROGRAM_SIZE];
    bool running;
} VM;

#endif