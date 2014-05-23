//writen by Ryan Huard
#include "Operations.h"

int main(void)
{
    int memory[SIZE_OF_MEMORY]; //the memory array
    int accumulator = 0; //the accumulator register
    int instruction_counter = 0; //location of memory the operation is being performed
    int instruction_register = 0; //holds the instruction word
    int operation_code = 0; //indicates operation being performed
    int operand = 0; //stores the location in memory on which the current instruction operates
    int good;
    int choice;//this is the choice of the user from the greet function

    initMemory(memory);
    choice = greet();

    if(choice == 1){
        //read form a file
        good = readFile(memory);

    }else if(choice == 2){
        //interactive prompt
        interactive(memory);



    }else if(choice == 3){
        //do nothing

    }else{
        //error
        printf("There was a serious error [0]");
    }

    //start running the SML code

    if(choice != 3 && good != 0){
        printf("\n***Starting SML code execution***\n\n");
        while(instruction_counter != DONE){

            //read word
            instruction_register = memory[instruction_counter];
            getOpeAndOper(instruction_register, &operation_code, &operand);

        //find instruction and execute the right one
            switch(operation_code){

            case NUMBER:
                number(&instruction_counter);
                break;
            case READ:
                read(memory, operand, &instruction_counter);
                break;
            case WRITE:
                write(memory, operand, &instruction_counter);
                break;
            case LOAD:
                load(memory, operand, &accumulator, &instruction_counter);
                break;
            case STORE:
                store(memory, operand, accumulator, &instruction_counter);
                break;
            case ADD:
                add(memory, operand, &accumulator, &instruction_counter);
                break;
            case SUBTRACT:
                subtract(memory, operand, &accumulator, &instruction_counter);
                break;
            case DIVIDE:
                divide(memory, operand, &accumulator, &instruction_counter);
                break;
            case MULTIPLY:
                multiply(memory, operand, &accumulator, &instruction_counter);
                break;
            case BRANCH:
                branch(operand, &instruction_counter);
                break;
            case BRANCHNEG:
                branchNeg(operand, accumulator, &instruction_counter);
                break;
            case BRANCHPOS:
                branchPos(operand, accumulator, &instruction_counter);
                break;
            case HALT:
                Halt(&instruction_counter);
                break;
            default:
                printf("there was an error [1] - unknown instruction\n");
                break;


            }
        }
    }



    return 0;
}
