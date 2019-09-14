#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "proto.h"

/*
 * iasm - Translator from IJVM Assembly language to machine code.
 * v0.1 13.09.2019
 * by Centrix
 */

int is_int(char *word) {
	int i = 0;
	while ( word[i] ) if ( !isdigit(word[i++]) ) return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	FILE *src;
	FILE *dest;

	char prog[256];
	char *tok;

	int comment = 0;

	if ( argc != 3 ) {
		fprintf(stderr, "Usage: iasm <src_file> <out_file>\n");
		return 0;
	}

	src = fopen(argv[1], "r");
	if ( src == NULL ) {
		fprintf(stderr, "Can`t open %s\n", argv[1]);
		return 0;
	}

	dest = fopen(argv[2], "w");
	if ( dest == NULL ) {
		fprintf(stderr, "Can`t open %s\n", argv[2]);
		return 0;
	}

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
