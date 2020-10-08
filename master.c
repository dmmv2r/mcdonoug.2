//Author: Donovan McDonough
//Date: 10/8/20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int opt;
	int totalChild;
	int maxChild;
	int termTime;
	char* input;

	bool argTotal;
	bool argMax;
	bool argTime;
	bool argIn;

	argTotal = false;
	argMax = false;
	argTime = false;
	argIn = false;

	while((opt = getopt(argc, argv, "hn:s:t:i:")) != -1) {
		switch(opt) {
			case 'h':
				printf("%s: Usage: %s -h (help) [-n x (number of child processes, default is 4)] [-s x (child processes at once, default is 2)] [-t x (seconds for process to terminate, default is 100)] [-i file (input file, default is palin.in)]\n", argv[0], argv[0]);
				return -1;
			case 'n':
				totalChild = atoi(optarg);
				argTotal = true;
				break;
			case 's':
				maxChild = atoi(optarg);
				argMax = true;
				break;
			case 't':
				termTime = atoi(optarg);
				argTime = true;
				break;
			case 'i':
				input = optarg;
				argIn = true;
				break;
			default:
				printf("Usage: %s...\n", argv[0]);
				return -1;
		}
	}

	if(!argTotal) {
		totalChild = 4;
	}
	if(!argMax) {
		maxChild = 2;
	}
	if(!argTime) {
		termTime = 100;
	}
	if(!argIn) {
		input = "palin.in";
	}

	printf("total = %d, max = %d, time = %d, file = %s\n", totalChild, maxChild, termTime, input);

	system("./palin");

	printf("ENDING MASTER\n");

	return 0;
}
