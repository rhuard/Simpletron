#ifndef ASSEMBLE_H
#define ASSEMBLE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE_OF_FILE_NAME 30
#define LINESIZE 15

#define READ 0
#define WRITE 1
#define LOAD 2
#define STORE 3
#define ADD 4
#define SUB 5
#define DIV 6
#define MUL 7
#define BRANCH 8
#define BRANCHNEG 9
#define BRANCHZERO 10
#define BRANCHPOS 11
#define HALT 12

int opcodes[13] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43, 50};

void Assemble(void);
int getOpCode(char *op);
int isMatch(char *op, char *input);
void writeAssemble(void);

#endif
