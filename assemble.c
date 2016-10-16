#include "assemble.h"

void Assemble(void){

    FILE *infile = NULL;
    FILE *outfile = NULL;
    char line[LINESIZE];
    char *tok;
    int opcode;
    int num;
    int final;
    char ass_file_name[SIZE_OF_FILE_NAME];
    char fullassname[SIZE_OF_FILE_NAME+10];
    char bin_file_name[SIZE_OF_FILE_NAME];
    char fullbinname[SIZE_OF_FILE_NAME+10];

    printf("Assembly File:\n");
    scanf("%s", ass_file_name);

    strcpy(fullassname, "simpleass/");
    strcat(fullassname, ass_file_name);

    printf("Bin File:\n");
    scanf("%s", bin_file_name);

    strcpy(fullbinname, "simplebin/");
    strcat(fullbinname, bin_file_name);

    infile = fopen(fullassname, "r");
    outfile = fopen(fullbinname, "w");

    if((outfile != NULL) && (infile != NULL)){

        while (!feof(infile)) {
            fgets(line, LINESIZE, infile);

            tok = strtok(line, " ");
            opcode = getOpCode(tok);
            if(opcode == -1){
                printf("ERROR assembling: %s\n", tok);
                fclose(infile);
                fclose(outfile);
                break;
            }else if(opcode == opcodes[HALT]){
                printf("assembly done\n");
                final = 5000;
                fprintf(outfile, "%d\n", final);
                fclose(infile);
                fclose(outfile);
                break;
            }else{
                tok = strtok(NULL, " ");
                num = atoi(tok);
                final = (opcode * 100) + num;
                fprintf(outfile, "%d\n", final);

            }
        }

    }else{
        printf("error invalid files\n");
    }
}

int isMatch(char *op, char *input){

    return (0 == strcmp(op, input));
}

int getOpCode(char *op){

    int opcode;

    if(isMatch(op, "read")){
        opcode =  opcodes[READ];
    }else if(isMatch(op, "write")){
        opcode = opcodes[WRITE];
    }else if(isMatch(op, "load")){
        opcode = opcodes[LOAD];
    }else if(isMatch(op, "store")){
        opcode = opcodes[STORE];
    }else if(isMatch(op, "add")){
        opcode = opcodes[ADD];
    }else if(isMatch(op, "sub")){
        opcode = opcodes[SUB];
    }else if(isMatch(op, "div")){
        opcode = opcodes[DIV];
    }else if(isMatch(op, "mul")){
        opcode = opcodes[MUL];
    }else if(isMatch(op, "branch")){
        opcode = opcodes[BRANCH];
    }else if(isMatch(op, "branchneg")){
        opcode = opcodes[BRANCHNEG];
    }else if(isMatch(op, "branchzero")){
        opcode = opcodes[BRANCHZERO];
    }else if(isMatch(op, "branchpos")){
        opcode = opcodes[BRANCHPOS];
    }else if(isMatch(op, "end\n")){
        opcode = opcodes[HALT];
    }else{
        opcode = -1;
    }

    return opcode;
}

void clearline(char *line){
    int i = 0;

    for(i = 0; i < LINESIZE; i++){

        *(line + i) = 0;
    }
}

void writeAssemble(void){

    FILE *outfile = NULL;
    char line[LINESIZE];
    char ass_file_name[SIZE_OF_FILE_NAME];
    char fullassname[SIZE_OF_FILE_NAME+10];
    char *l = line;
    size_t bytes = LINESIZE;
    int con = 1;

    printf("Assembly File:\n");
    scanf("%s", ass_file_name);

    strcpy(fullassname, "simpleass/");
    strcat(fullassname, ass_file_name);

    outfile = fopen(fullassname, "w");

    printf("type code\n enter DONE when you are done\n");
    while(con){

        clearline(line);
        getline(&l, &bytes, stdin);
        if(1 == con){
            con++;
            continue;
        }
        if(0 == strcmp(line, "DONE\n")){
            break;
        }else{
            fprintf(outfile, "%s", line);
        }
    }

    fclose(outfile);
    return;
}
