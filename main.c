#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "proto.h"

int is_int(char *word) {
	int i = 0;
	while ( word[i] ) if ( !isdigit(word[i++]) ) return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	FILE *src = fopen(argv[1], "r");
	FILE *dest = fopen(argv[2], "w");

	char prog[256];
	char *tok;

	int comment = 0;

	fgets(prog, 256, src);
	tok = strtok(prog, " ,\n");

	while ( !feof(src) ) {
		while ( tok != NULL ) {
			if ( !strcmp(tok, "`") )
				comment = !comment;
			else if ( !comment ) {
				if ( is_int(tok) )
					putc(atoi(tok), dest);
				else {
					if ( get_opcode(tok) != -1 )
						putc(get_opcode(tok), dest);
					else
						printf("error %s\n", tok);
				}
			}
			tok = strtok(NULL, " ,\n");
		}
		fgets(prog, 256, src);
		tok = strtok(prog, " ,\n");
	}
	fclose(src);
	fclose(dest);
	return 0;
}
