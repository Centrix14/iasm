#include <stdio.h>
#include <string.h>

int find(char *list[], char *str, int range) {
	for ( int i = 0; i < range; i++ )
		if ( !strcmp(list[i], str) ) return i;
	return -1;
}

int get_opcode(char *cmd) {
	char *commands[] = {"bipush", "dup", "goto", "iadd", "iand", "ifeq", "iflt", "if_icmpeq", "iinc", "iload", "invokevirtual", "ior", "ireturn", "istore", "isub", "ldc_w", "nop", "pop", "swap", "wide"};
	int opcodes[] = {0x10, 0x59, 0xA7, 0x60, 0x7E, 0x99, 0x9B, 0x9F, 0x84, 0x15, 0xB6, 0x80, 0xAC, 0x36, 0x64, 0x13, 0x00, 0x57, 0x5F, 0xC4};
	int list_lenght = 20;
	int res = find(commands, cmd, list_lenght);

	if ( res >= 0 ) return opcodes[res];
	else return -1;
}
