#include<stdio.h>

typedef struct{
    const char *name;
    int opcode;
} InstructionMapping;

// InstructionMapping InstructionTable[] = {
//     {"PSH", PSH},
//     {"ADD", ADD},
//     {"POP", POP},
//     {"SET", SET},
//     {"HLT", HLT}
// }