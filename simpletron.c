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
        printf("would you like to:\n");
        printf("1 - read from a file\n");
        printf("2 - enter the interactive prompt\n");
        printf("3 - run simpletron assembler\n");
        printf("4 - write simpltron assembler code\n");
        printf("-1 - exit\n:");

        scanf("%d", &choice);

        if(choice != 1 && choice != 2 && choice!= 3 && choice != 4 && choice != -1){

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

printf("******please enter your program instructions******\n");
printf("when you are done, please type the sentinal -9999 to immediately execute\n");
printf("or -9998 to save into file\n");
getInput(memory);

}

/**initMemory
initalizes the memory array
input: memory array
output: void
predcondition: program starts
postcondition: whole memory array will be initalized to 0
created: 28 Aug 2013
last update: 28 Aug 2013**/
void initMemory(int memory[SIZE_OF_MEMORY]){

    int i;
    for(i = 0; i<SIZE_OF_MEMORY; i++){

        memory[i] = 0;
    }
}

int saveFile(int memory[SIZE_OF_MEMORY]){

    FILE *outfile = NULL;
    char file_name[SIZE_OF_FILE_NAME];
    char fullname[SIZE_OF_FILE_NAME+10]; //10 is from 'simplebin/' for docker container
    int i = 0;

    printf("filename:\n");
    scanf("%s", file_name);

    strcpy(fullname, "simplebin/");
    strcat(fullname, file_name);

    outfile = fopen(fullname, "w");

    if(outfile != NULL){

        while(memory[i] != -9998){

            fprintf(outfile,"%d\n", memory[i]);
            i++;
        }

        return i;

    }else{

        printf("error: file could not be opened\n");
        return -1;
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

        else if(memory[i] == -9998){

            saveFile(memory);
            i = SIZE_OF_MEMORY;
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
int readFile(int memory[SIZE_OF_MEMORY]){

    FILE *infile = NULL;
    char file_name[SIZE_OF_FILE_NAME];
    char fullname[SIZE_OF_FILE_NAME+10]; //10 is from 'simplebin/' for docker container
    int i = 0;

    printf("filename:\n");
    scanf("%s", file_name);

    strcpy(fullname, "simplebin/");
    strcat(fullname, file_name);

    infile = fopen(fullname, "r");
    if(infile != NULL){

        while(!feof(infile)){

            fscanf(infile, "%d", &memory[i]);
            i++;
        }

        fclose(infile);
        return 1;

    }else{

        printf("error - file could not be opened\n");
        return 0;
    }
}

/**get Operator and Operand
seperates the word into an operator and an operand
input: the word to seperate and output perameters for the operator and the operand
output: void
preconditions: a word needs to be read
postconditions: a word will be seperated
created: 31 dec 2013
last update: 31 dec 2013**/
void getOpeAndOper(int word, int *oper, int *operand){

    *oper = word / 100;
    *operand = word % 100;
}
