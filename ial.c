#include <stdio.h>

/*
 * ial - concatenator files.
 * v0.1 14.09.2019
 * by Centrix
 */

int main(int argc, char *argv[]) {
	FILE *res, *src;
	int i = 2, byte = 0;

	if ( argc < 2 ) {
		fprintf(stderr, "Usage: ial <result_file> <file1> <file2>...\n");
		return 0;
	}
	res = fopen(argv[1], "w");
	if ( res == NULL ) {
		fprintf(stderr, "Can`t open %s\n", argv[1]);
		return 0;
	}

	src = fopen(argv[i], "r");
	while ( i < argc ) {
		if ( src == NULL ) {
			fprintf(stderr, "Can`t open %s\n", argv[i]);
		}

		byte = fgetc(src);
		while ( byte != EOF ) {
			fputc(byte, res);
			byte = fgetc(src);
		}

		i++;
		freopen(argv[i], "r", src);
	}

	fclose(res);
	fclose(src);

	return 0;
}
