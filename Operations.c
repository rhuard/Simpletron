//this file will hold all of the operation code, for all other functions please see the simpletron.c file

#include "simpletron.h"

/**Read
reads a word from the terminal into a specific location in memory
input: the location of memory to read into (the operand), and the memory array, and a pointer to the instuction_counter
output: void
preconditions: this operation has been called
postconditions: a value will be read into the memory
created: 21 Oct 2013
last updated: 21 Oct 2013**/
void read(int memory[SIZE_OF_MEMORY], int operand, int *instruction_counter){

    int word;

    printf("? ");
    scanf(" %d", &word);
    *instruction_counter += 1;//increases the instrcution counter to the next spot in memory


    memory[operand] = word;
}

/**Write
writes a word from a specific location in memory to the terminal
intput: the operand and the memory array pointer to the instruction counter
output: void
preconditions: this operation has been called
postconditions: a value from memory will be uploaded to the terminal and the instruction counter will be increased by one
created: 21 Oct 2013
last updated: 21 Oct 2013**/
void write(int memory[SIZE_OF_MEMORY], int operand, int *instruction_counter){

    printf(":%d\n", memory[operand]);
    *instruction_counter += 1;//increases the instrcution counter to the next spot in memory

}

/**Load
 loads a word from a specific location in memory into the accumulator
 intput: the operand, the memory array and a pointer to the accumulator
 output: void
 preconditions: this operation has been called
 postconditions: the acmulator will have the new value stored
 created: 21 Oct 2013
last updated: 21 Oct 2013**/
void load(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter){

     *accumulator = memory[operand];
     *instruction_counter += 1;
}

/**Store
stares the value in the accumulator into a specific location in memory
intput: the operand, the memory array  and the accumulator
output: void
preconditions: this operation has been called
postconditions: the value from the accumulator will be stored in the memory array
created: 21 Oct 2013
last updated: 21 Oct 2013**/
void store(int memory[SIZE_OF_MEMORY], int operand, int accumulator, int *insturction_counter){

    memory[operand] = accumulator;
    *insturction_counter += 1;
}

/**Add
adds a word from a specific location in memory to the accumulator(result left in accumulator)
input: the operand, memory array and a pointer to the accumulator
output: void
preconditions: this operation has been called
postconditions: the accumulator will hold the sum of the old accumulator and the operand
created: 21 Oct 2013
last update: 21 Oct 2013**/
void add(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter){

    *accumulator += memory[operand];
    *instruction_counter += 1;
}

/**Subtract
subtracts a word from a specific location in memory from the accumulator(result left in accumulator)
input: the operand, memory array and a pointer to the accumulator
output: void
preconditions: this operation has been called
postconditions: the accumulator will hold the difference of the old accumulator and the operand
created: 21 Oct 2013
last update: 21 Oct 2013**/
void subtract(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter){

    *accumulator -= memory[operand];
    *instruction_counter += 1;
}

/**Multiply
multplies a word from a specific location in memory with the accumulator(result left in accumulator)
input: the operand, memory array and a pointer to the accumulator
output: void
preconditions: this operation has been called
postconditions: the accumulator will hold the product of the old accumulator and the operand
created: 21 Oct 2013
last update: 21 Oct 2013**/
void multiply(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter){

    *accumulator *= memory[operand];
    *instruction_counter += 1;
}

/**Divide
divides a word from a specific location in memory by the accumulator(result left in accumulator)
input: the operand, memory array and a pointer to the accumulator
output: void
preconditions: this operation has been called
postconditions: the accumulator will hold the quotant of the old accumulator and the operand
created: 21 Oct 2013
last update: 21 Oct 2013**/
void divide(int memory[SIZE_OF_MEMORY], int operand, int *accumulator, int *instruction_counter){

    *accumulator /= memory[operand];
    *instruction_counter += 1;
}

/**Branch
branches to a specific location in memory
input: the operand, a pointer to the instruction counter
output: void
preconditions: this operation has been called
postconditions: the instruction counter will be branched to another location in memory
created: 22 Oct 2013
last update: 22 Oct 2013**/
void branch(int operand, int *instuction_counter){

    *instuction_counter = operand;
}

/**Branch Negitive
branches to a specific location in memory if the accumulator is negative
input: the operand, the accumulator, a pointer to the instruction counter
output: void
preconditions: this operation has been called
postconditions: the instruction counter will be branched to another location in memory if the accumulator is negetive, else it will update the instruction_coounter onto the next word
created: 22 Oct 2013
last update: 22 Oct 2013**/
void branchNeg(int operand, int accumulator, int *instruction_counter){

    if(accumulator < 0){
        *instruction_counter = operand;
    }else{

        *instruction_counter += 1;
    }
}

/**Branch Zerro
branches to a specific location in memory if the accumulator is zerro
input: the operand, the accumulator, a pointer to the instruction counter
output: void
preconditions: this operation has been called
postconditions: the instruction counter will be branched to another location in memory if the accumulator is zerro, else it will update the instruction_coounter onto the next word
created: 22 Oct 2013
last update: 22 Oct 2013**/
void branchZerro(int operand, int accumulator, int *instruction_counter){

    if(accumulator == 0){
        *instruction_counter = operand;
    }else{

        *instruction_counter += 1;
    }
}

/**Branch Postivive
branches to a specific location in memory if the accumulator is positive
input: the operand, the accumulator, a pointer to the instruction counter
output: void
preconditions: this operation has been called
postconditions: the instruction counter will be branched to another location in memory if the accumulator was positive, else it will update the instruction_coounter onto the next word
created: 22 Oct 2013
last update: 22 Oct 2013**/
void branchPos(int operand, int accumulator, int *instruction_counter){

    if(accumulator > 0){
        *instruction_counter = operand;
    }else{

        *instruction_counter += 1;
    }
}

/**Halt
displays message to terminal about program being finished
input: pointer to the instuction_counter
output: void
preconditions: this operation has been called
postconditions: the simpletron program will be compleated, a message will be displayed and the instruction counter will be set to the DONE value
created: 22 Oct 2013
last updated: 22 Oct 2013**/
void Halt(int *instruction_counter){

    printf("\n***the simpletron program has finished execution succesfully***\n");
    *instruction_counter = DONE;

}


/**number
if the word is a number, then the instruction should be skipped
input: a pointer to the instruction counter
output: void
precondition: this operation has been called
postcondtions: the next instruction will be able to execute
created: 30 dec 2013
last updated: 30 dec 2013**/
void number(int *instruction_counter){

    *instruction_counter += 1;
}
