#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_MEMORY 100
//operation codes
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define BRANCHPOS 43
#define HALT 44
#define DONE -1 //this defines when the program is done. The instruction counter will be set to this value

void greet(void);

void getInput(int memory[SIZE_OF_MEMORY]);

void initMemory(int memory[SIZE_OF_MEMORY]);

//operation functions
void read(int memory[SIZE_OF_MEMORY], int operand, int *instruction_counter);
void write(int memory[SIZE_OF_MEMORY], int operand, int *instruction_counter);
void load(int memory[SIZE_OF_MEMORY], int operand, int *accumulator);
void store(int memory[SIZE_OF_MEMORY], int operand, int accumulator);
void add(int memory[SIZE_OF_MEMORY], int operand, int *accumulator);
void subtract(int memory[SIZE_OF_MEMORY], int operand, int *accumulator);
void multiply(int memory[SIZE_OF_MEMORY], int operand, int *accumulator);
void divide(int memory[SIZE_OF_MEMORY], int operand, int *accumulator);
void branch(int operand, int *instuction_counter);
void branchNeg(int operand, int accumulator, int *instruction_counter);
void branchZerro(int operand, int accumulator, int *instruction_counter);
void branchNeg(int operand, int accumulator, int *instruction_counter);

#endif
