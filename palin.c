

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	printf("YOU ARE IN PALIN.C\n");

	FILE *ptr;
	char* str;
	str = argv[1];

	printf("%s\n", str);
	printf("%c\n", str[3]);

	int l = 0;
	int h = strlen(str) - 1;

	//l = 0;
	//h = strlen(str) - 1;

	while(h > 1) {
		if(str[l++] != str[h--]) {
			printf("Is not a palindrome\n");
			ptr = fopen("nopalin.out", "a");
			fprintf(ptr, "%s\n", str);
			fclose(ptr);
			printf("bye\n");
			return 0;
		}
	}

	printf("Is a palindrome\n");
	ptr = fopen("palin.out", "a");
	fprintf(ptr, "%s\n", str);
	fclose(ptr);
	printf("YOU ARE LEAVING PALIN.C\n");
	return 0;
}
