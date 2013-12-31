//this file will hold the functions that are not operations, for those please see the Operations.c file

#include "simpletron.h"

/**greet
prints welcome screen, and the user chooses to run the interactive or read in from a file
input: void
output: an int for if the user would like to read from a file or if the user would like to input the SML themselves
preconditions: program starts
created: 30 Dec 2013
last updated: 30 Dec 2013**/
int greet(void){

    int choice;
    int con = -1;

    while(con != 1){
        printf("***Welcome to the Simpletron Computer Simulator***\n");
        printf("\nwould you like to:\n1-read from a file\n2-enter the interactive prompt\n3-exit\n:");

        scanf("%d", &choice);

        if(choice != 1 && choice != 2 && choice!= 3){

            printf("That was an invalid option please try again\nplease press anykey to continue\n");
            getchar();

        }else{

            con = 1;
        }
    }
    return choice;
}

/**interactive
gives the greeting to the user
input: void
output: void
preconditions: user choses interactive console
postconditions: user will start using simpletron
created: 27 Aug 2013
last update: 30 dec 2013

    update record:
        30dec 2013 - changed name to interactive, as the program is being adapted to read in from a file as well as the interactive prompt. Also added the  getInput function**/
void interactive(int memory[SIZE_OF_MEMORY]){

printf("******please enter your program instructions***\n***one word at a time, each time***\n***you will be prompted with the memory location you are***\n***using for that instruction***\n\n***when you are done, please type the sentinal -9999***\n\n\n");
getInput(memory);

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

/**readFile
reads a user input file for the SML code
input: the memory array to populate
output: void
preconditions: the user wants to read in from a file
postconditions: a SML program will be read from the requested file to the memory array
created: 31 dec 2013
last updated: 31 dec 2013**/
void readFile(int memory[SIZE_OF_MEMORY]){

    FILE *infile;
    char *filename;
    int i = 0;

    printf("Please enter file name: ");
    scanf("%s", filename);

    infile = fopen(filename, "r");

    //TODO: put in check to make sure file is open

    while(!feof(infile)){

        memory[i] = fscanf(infile, "%d");
        i++;
    }
}

//TODO: driver for running the simpletron program
