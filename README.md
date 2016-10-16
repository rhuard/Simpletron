# Simpletron #

Simpletron simulator in C. A simpletron is a program that simulates a simple computer. Where the user can enter in a simple program in the Simpletron Machine Language (SML).

## executing ##

The simpletron program can be compiled and ran localy:
```bash
make all
./run
```

This project also comes has been dockerized and the container can be built by running
```bash
make build
```
you can execute `dockerrun` in order to execute the docker container

This project was started my freshman year of college... so some of the code needs to be updated. This will be happening over time as I have time

## SML ##

### Design of Machine ###
SML is writen in signed integers called words. Each word is either data or an instruction. All instructions are assumed to be positive in value, data may either be positive or negetive. All instructions are four digit words.

In the case of an instruction, the first two digits are the operation code and the last two are the location of memory for the data being operated on.

Math is done with the use of the accumulator, the load command must be used to load a value into the accumulator, then an operation must be called, the result is then left in the accumulator.

The memory is a single array of 100 integers referenced as slots 0 - 99. This includes the data and text part of an sml code. Text for the programs are writen to the beginning of the memory (strting at 0) Therefore, it is recommended to reserve space for variables starting from 99.

### Commands ###

10 read - read a word from the terminal into a specific location in memory

11 write - write a word from a specific location in memorry to the terminal

20 load - load a word from a specific location in memory into the accumulator

21 store - store a word from the accumulator into a speficif location in memory

30 add - add a word from a spefici location in memory to the word in the accumulator (leaving the result in the accumulator)

31 subtract  - subtract a word from a specifc location in memory from the word in the accumulator (leave result in accumulator)

32 divide - divide a word from a specific location in memory into the word in the accumulator (leaving result in accumulator)

33 multiply -  divide a word from a specific location in memory into the word in the accumulator (leaving result in accumulator)

40 branch - branch to a specific location in memory

41 branchneg - branch to a specific location in memory if the accumulator is negative

42 branchzero - Branch to a specific location in memory if the accumulator is zero

43 branchpos - Branch to a specific location in memory if the accumulator is positive

50 halt - called when the program is done with its task

### Assembly Language ###

Support has been added so that a simple assembly language can be used instead of writing the byte code directly. The assembly language uses the same names as the bytecode commands. The assembly language is made in the structure `op num`. For example:
```
read 99
write 99
```
is equivalent to 
```
1099
1199
```

#### credits ####
The idea for this program is from the seventh edition of C how to Program from Deitel.
