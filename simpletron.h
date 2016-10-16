#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_MEMORY 100
#define SIZE_OF_FILE_NAME 30
//operation codes
#define NUMBER 0
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define BRANCHPOS 43
#define HALT 50
#define DONE -9999 //this defines when the program is done. The instruction counter will be set to this value

int greet(void);
void interactive(int memory[SIZE_OF_MEMORY]);
void getInput(int memory[SIZE_OF_MEMORY]);
void initMemory(int memory[SIZE_OF_MEMORY]);
int readFile(int memory[SIZE_OF_MEMORY]);
void getOpeAndOper(int word, int *oper, int *operand);

#endif
