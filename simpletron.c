//this file will hold the functions that are not operations, for those please see the Operations.c file

#include "simpletron.h"

/**greet
gives the greeting to the user
input: void
output: void
preconditions: program starts
postconditions: user will start using simpletron
created: 27 Aug 2013
last update: 27 Aug 2013**/
void greet(void){

printf("***Welcome to Simpletron***\n***please enter your program instructions***\n***one word at a time, each time***\n***you will be prompted with the memory location you are***\n***using for that instruction***\n\n***when you are done, please type the sentinal -9999***\n\n\n");

}

/**initMemory
initalizes the memory array
input: memory array
output: void
predcondition: program starts
postcondition: whole memory array will be initalized to -9999
created: 28 Aug 2013
last update: 28 Aug 2013**/
void initMemory(int memory[SIZE_OF_MEMORY]){

    int i;
    for(i = 0; i<SIZE_OF_MEMORY; i++){

        memory[i] = -9999;
    }
}

/**getInput
gets the program the user wants to run
input: four digit integers that make up the SML
output: void
preconditions: program starts
Postconditions: a SML program will be in the memory array
created: 28 Aug 2013
last update: 28 Aug 2013**/
void getInput(int memory[SIZE_OF_MEMORY]){

    int i;

    for(i = 0; i<SIZE_OF_MEMORY; i++){
        printf("%d? ", i);
        scanf("%d", &memory[i]);

        if(memory[i] == -9999){//done with inputing instructions

            i = SIZE_OF_MEMORY;//end loop
        }
    }
}

//TODO: functions to figure out if the word is an instruction and if so split it up into operand and operation code

//TODO: driver for running the simpletron program
