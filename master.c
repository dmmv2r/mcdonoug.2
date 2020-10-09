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

	if(!argTotal) { //sets default number of lines to read
		totalChild = 4;
	}
	if(!argMax) { //sets default number of processes at one time
		maxChild = 2;
	}
	if(!argTime) { //sets default amount of time program is running
		termTime = 100;
	}
	if(!argIn) { //sets default input file
		input = "palin.in";
	}

	printf("total = %d, max = %d, time = %d, file = %s\n", totalChild, maxChild, termTime, input);

	FILE *file = fopen(input, "r");
	if(file == NULL) { //error message if input file fails to open
		perror("Invalid input");
		return -1;
	}

	int arrSize = totalChild * 80; //finds size of array needed
	char sArr[arrSize]; //creates array of needed size for all input line
	int j;
	int count = 1;

	j = -1;
	do { //gets all required lines into single array
		j++;
		sArr[j] = fgetc(file);
		if(sArr[j] == '\n') { //detects end of line
			if(count == totalChild) {
				sArr[j] = '\0'; //inserts null at end of array
			}
			count++;
		}
	}while(sArr[j] != EOF && count <= totalChild);
	fclose(file);


	char* palin = "./palin";
	pid_t pid = fork();
	if(pid < 0) {
		perror("fork failed");
		exit(1);
	}
	else if(pid == 0) { //child
		char arr[80];
		int i = -1;

		do { //gets line of input file
			i++;
			arr[i] = sArr[i];
			if(arr[i] == '\n') {
				arr[i] = '\0'; //inserts null character instead of end of line
			}
		}while(arr[i] != '\0' && i < 80);

		printf("Executing child\n");
		execvp(palin, arr); //DOES NOT WORK
		return 0;
	}

	printf("Parent is waiting\n");
	wait(NULL);

	printf("ENDING MASTER\n");

	return 0;
}



