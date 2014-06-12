/* Os42 Kernel */

#include <stdint.h>

#include "vga.h"

void puts(char* s);

/* Entry point for the kernel */
void kernel_main() {
	uint8_t i;
	vga_color fg = COLOR_YELLOW;
	vga_color bg = COLOR_MAGENTA;
	
	vga_init();
	vga_set_color(fg, bg);
	puts("Hello World!");
	
	for (i = 0; i < 255; i++) {
		vga_current_color = i;
		puts("Hello World!");
	}
}

void puts(char* s) {
	int i;
	
	for (i = 0; s[i] != 0; i++) {
		vga_putchar(s[i]);
	}
}
