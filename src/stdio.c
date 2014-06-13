/* Os42
 * 
 * Standard Input / Output Library
 * File: stdio.c
 */

#include <stdio.h>

/** Prints a character to the screen
 * @param c character to print
 */
void putc(char c) {
	vga_putchar(c);
	vga_update_cursor();
	return;
}

/** Prints a string to the screen
 * @param s string to print
 */
void puts(char* s) {
	int i;
	
	for (i = 0; s[i] != 0; i++) {
		vga_putchar(s[i]);
	}
	
	vga_update_cursor();
	return;
}
