#include "simpletron.h"

int main(void)
{
    int memory[100]; //the memory array
    int accumulator = 0000; //the accumulator register
    int instruction_counter = 00, instruction_register = 00, operation_code = 00, operad = 00;

    greet();
    getInput(memory);

    return 0;
}
