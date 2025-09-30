# Stack Based Virtual Machine
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)

A simple stack-based virtual machine built in C++. This project was inspired by Felix Angell's tutorial and serves as a stepping stone to better understand computer architecture and build more complex projects like a CHIP-8 virtual machine or an NES emulator.

## Core functionality

* **Instructions**: Implemented 5 instructions to manipulate the stack and registers.
    * `PSH <value>`: Pushes a value onto the stack.
    * `ADD`: Pops two values from the stack, adds them, and pushes the result back.
    * `POP`: Pops a value from the stack and prints it to the console.
    * `SET <register> <value>`: Sets a register to the specified value.
    * `HLT`: Halts execution.
* **Registers**: Includes 8 general-purpose registers, plus the Stack Pointer (SP) and Instruction Pointer (IP).
* **Assembler**: A simple assembler is included to convert assembly-like text files into machine code that the VM can execute.


## Prerequisites

* A C++ compiler that supports C++11 (e.g., g++, Clang).
* The `make` build automation tool.

## Try for yourself

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Shanwis/Stack-Based-Virtual-Machine.git
    cd Stack-Based-Virtual-Machine
    ```
2. **Run the VM**:
    ```
    make
    make run <file to run>
    ```

3.  **Write a program:**
    Create a new file, for example `my_program.asm`, with instructions for the VM.

    **`my_program.asm`**
    ```asm
    ; Pushes 5 and 10 to the stack, adds them, and prints the result (15)
    PSH 5
    PSH 10
    ADD
    POP
    HLT
    ```

4.  **Run the program:**
    Use the `make run` command and pass the program file path as an argument.
    ```bash
    make run program=my_program.asm
    ```
    *Note: The `program=` part is important!*

5. **Clean up after use**:
    ```
    make clean
    ```

## Future Scope

This is quite a simple VM. I wish to make a CHIP-8 VM in the near future as an excersise and run a tetris ROM in it. 

This was a great learning experience, maybe I will try adding a few more stuff to it, before going to more advanced topic.


