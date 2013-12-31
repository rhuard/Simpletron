//writen by Ryan Huard
#include "simpletron.h"

int main(void)
{
    int memory[SIZE_OF_MEMORY]; //the memory array
    int accumulator = 0; //the accumulator register
    int instruction_counter = 0; //location of memory the operation is being performed
    int instruction_register = 0; //holds the instruction word
    int operation_code = 0; //indicates operation being performed
    int operand = 0; //stores the location in memory on which the current instruction operates

    int choice;//this is the choice of the user from the greet function

    choice = greet();

    if(choice == 1){
        //read form a file
        readFile(memory);

    }else if(choice == 2){
        //interactive prompt
        interactive(memory);



    }else if(choice == 3){
        //do nothing

    }else{
        //error
        printf("There was a serious error [0]");
    }

    return 0;
}
