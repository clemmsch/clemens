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
		TokenList tokens;
		createTokenList(&tokens, 1);
		ParserStatus pstat = startParser(&tokens, source);
		if (pstat != PARSER_SUCESS)
			return 1;

		for (int i = 0; i < tokens.ptr; i++) {
			Token* t = getTokenFromList(&tokens, i);
			printf("%d, %d, %d\n", t->type, t->data, t->line);
		}

		// free(tokens);
		free(source);
	}

	
	return 0;
}