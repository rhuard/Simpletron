Simpletron
==========

Simpletron simulator in C. A simpletron is a program that simulates a simple computer. Where the user can enter in a simple program in the Simpletron Machine Language (SML).

I am making this project to help keep me in practice with using C.

The idea for this program is from the seventh edition of C how to Program from Deitel.


SML:

SML is writen in signed integers called words. Each word is either data or an instruction. All instructions are assumed to be positive in value, data may either be positive or negetive. All instructions are four digit words.

In the case of an instruction, the first two digits are the operation code (what tells the simpletron which operation is geing used) and the last two are the location of memory for the data being operated on. 
Math is done with the use of the accumulator, the load command must be used to load a value into the accumulator, then an operation must be called, the result is then left in the accumulator.

The comands and their operation code are as writen bellow:
10 Read - read a word from the terminal t=into a specific location in memory
11 write - write a word from a specific location in memorry to the terminal
20 load - load a word from a speficif location in memory into the accumulator
21 store - store a word from the accumulator into a speficif location in memory
30 add - add a word from a spefici location in memory to the word in the accumulator (leaving the result in the accumulator)
31 subtract  - subtract a word from a specifc location in memory from the word in the accumulator (leave result in accumulator)
32 divide - divide a word from a specific location in memory into the word in the accumulator (leaving result in accumulator)
33 multiply -  divide a word from a specific location in memory into the word in the accumulator (leaving result in accumulator)
40 branch - branch to a specific location in memory
41 branchneg - branch to a specific location in memory if the accumulator is negative
42 branchzero - Branch to a speficif location in memory if the accumulator is zero
43 halt - called when the program is done with its task

more operations may be added in the future
