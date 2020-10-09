//Author: Donovan McDonough
//Date: 10/8/20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	printf("YOU ARE IN PALIN.C\n");

	FILE *ptr;
	char* str;
	str = argv[1];

	int l = 0;
	int h = strlen(str) - 1;

	while(h > 1) {
		if(str[l++] != str[h--]) { //detects if string is not a palindrome
			ptr = fopen("nopalin.out", "a"); //opens nopalin.out
			fprintf(ptr, "%s\n", str); //writes to output file
			fclose(ptr); //closes nopalin.out
			printf("bye\n");
			return 0;
		}
	}

	ptr = fopen("palin.out", "a"); //opens palin.out
	fprintf(ptr, "%s\n", str); //writes to output file
	fclose(ptr); //closes palin.out
	printf("YOU ARE LEAVING PALIN.C\n");
	return 0;
}
