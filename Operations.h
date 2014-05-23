#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "simpletron.h"

//operation functions
void number(int *instruction_counter);
void read(int memory[SIZE_OF_MEMORY], int operand, int *instruction_counter);
void write(int memory[SIZE_OF_MEMORY], int operand, int *instruction_counter);
void load(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter);
void store(int memory[SIZE_OF_MEMORY], int operand, int accumulator, int *instruction_counter);
void add(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter);
void subtract(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter);
void multiply(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter);
void divide(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter);
void branch(int operand, int *instuction_counter);
void branchNeg(int operand, int accumulator, int *instruction_counter);
void branchZerro(int operand, int accumulator, int *instruction_counter);
void branchNeg(int operand, int accumulator, int *instruction_counter);

#endif
