/* Os42 Kernel */

#include <stdint.h>

#include <stdio.h>
#include <vga.h>

/* Entry point for the kernel */
void kernel_main() {
	uint8_t i;
	vga_color fg = COLOR_YELLOW;
	vga_color bg = COLOR_MAGENTA;
	
	vga_init();
	vga_set_color(fg, bg);
	puts("Hello World!");
}
