#include <stdio.h>

/*
 * bfv - Compiled file viewer.
 * v0.1 14.09.2019
 * by Centrix
 */

int main(int argc, char *argv[]) {
	FILE *src;
	int byte = 0;

	if ( argc < 2 ) {
		fprintf(stderr, "Usage: bfv <file>\n");
		return 0;
	}

	src = fopen(argv[1], "rb");
	if ( src == NULL ) {
		fprintf(stderr, "Can`t open %s\n", argv[1]);
	}

	byte = fgetc(src);
	while ( byte != EOF ) {
		printf("%X ", byte);
		byte = fgetc(src);
	}

	return 0;
}
