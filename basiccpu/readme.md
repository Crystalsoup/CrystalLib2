# Basiccpu
As it sounds.
  Working principle is very simple;
  memory is defined as 100, it means that it is indexed to 0-99.

  arrays:
  'memory[]' stores instructions and 'data[]' stores integers.

  registers:
  - accumulator: holds the current number thats being worked on
  - pc: program counter

How it works

We manually fill in the memory like this:

```c
memory[0] = "LOAD 10";
memory[1] = "ADD 11";
memory[2] = "STORE 12";
memory[3] = "PRINT";
memory[4] = "END";
                               >load data[10]
                               >add data[11]
                               >store the result into data[12]
                               >print the result
                               >then stop the program
```
then the slots are given actual values:
```
memory[10] = "5";
memory[11] = "9";
memory[12] = "0";
```
atoi() converts strings to integers. they are stored in data[]
it allows cpu to work with numbers
  
