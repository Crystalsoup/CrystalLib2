#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 100

char* memory[MEM_SIZE];
int data[MEM_SIZE];

int accumulator = 0;
int pc = 0;

void run_cpu() {
	char instr[10];
	int arg;

	while (1) {
		if (memory[pc] == NULL || strcmp(memory[pc], "END") == 0) {
			printf("Program ended.\n");
			break;
		}

		if (sscanf(memory[pc], "%s %d", instr, &arg) < 1) {
			printf("Invalid instruction at %d\n", pc);
			break;
		}

		if (strcmp(instr, "LOAD") == 0) {
			accumulator = data[arg];
		} else if (strcmp(instr, "ADD") == 0) {
			accumulator += data[arg];
		} else if (strcmp(instr, "STORE") == 0) {
			data[arg] = accumulator;
		} else if (strcmp(instr, "PRINT") == 0) {
			printf("Accumulator: %d\n", accumulator);
		} else {
			printf("Unknown instruction: %s\n", instr);
			break;
		}

		pc++;
	}
}

int main() {
	memory[0] = "LOAD 10";
	memory[1] = "ADD 11";
	memory[2] = "STORE 12";
	memory[3] = "PRINT";
	memory[4] = "END";

	memory[10] = "5";
	memory[11] = "9";
	memory[12] = "0";

	for (int i = 10; i <= 12; i++) {
		data[i] = atoi(memory[i]);
	}

	run_cpu();
	return 0;
}