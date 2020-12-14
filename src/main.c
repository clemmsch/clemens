#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"
#include "../include/parser.h"

// cles compile file.cles

int main(int argc, char** argv) 
{
	if (argc <3) {
		printf("Too few arguments\n");
		return 1;

	}

	if (strcmp(argv[1], "compile") == 0) {
		char* source = readAsciiFile(argv[2]);
		printf("%s\n", source);
		TokenList* tokens;


		free(tokens);
		free(source);
	}

	
	return 0;
}