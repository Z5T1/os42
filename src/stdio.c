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

/** Prints an integer to the screen
 * @param d integer to print
 */
void puti(uint32_t d) {
	int i;
	
	if (d / 1000000000)	vga_putchar(d / 1000000000 + 48);
	for (i = 1000000000; i > 1; i /= 10) {
		if (d / (i / 10)) vga_putchar( (d % i * 10) / i + 48);
	}
	vga_update_cursor();
}

/** Prints an integer to the screen in hexadecimal
 * @param d integer to print
 */
void puth(uint32_t d) {
	int i, p;
	
	if (d / 0x10000000)	{
		p = d / 0x10000000;
		if ( p < 10 ) vga_putchar( p + 48 );
		else vga_putchar( p + 55 );
	}
	for (i = 0x10000000; i > 1; i /= 0x10) {
		if (d / (i / 0x10)) {
			p = (d % i * 0x10) / i;
			if ( p < 10 ) vga_putchar( p + 48 );
			else vga_putchar( p + 55 );
			
		}
	}
	vga_update_cursor();
}
