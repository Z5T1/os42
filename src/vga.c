/* Os42
 * 
 * VGA Driver
 * File: vga.c
 */

#include <vga.h>

/** Initializes the VGA driver.
 * This must be called before attempting to use any other part of the
 * VGA driver.
 */
void vga_init() {
	// Initialize Variables
	vga_buffer = (uint16_t*) 0xB8000;
	vga_row = 0;
	vga_column = 0;
	vga_current_color = 0x07;
	return;
}

/** Sets the VGA foreground color
 * @param color the new foreground color
 */
void vga_set_fg(vga_color color) {
	vga_current_color &= 0xF0;
	vga_current_color |= color;
	return;
}

/** Sets the VGA background color
 * @param color the new background color
 */
void vga_set_bg(vga_color color) {
	vga_current_color &= 0x0F;
	vga_current_color |= color << 4;
	return;
}

/** Sets the VGA foreground and background colors
 * @param fg the new foreground color
 * @param bg the new background color
 */
void vga_set_color(vga_color fg, vga_color bg) {
	vga_current_color = fg | bg << 4;
	return;
}

/** Gets the current VGA foreground color
 * @return the current foreground color
 */
vga_color vga_get_fg() {
	return vga_current_color & 0x0F;
}

/** Gets the current VGA background color
 * @return the current background color
 */
vga_color vga_get_bg() {
	return vga_current_color & 0xF0 >> 4;
}

/** Prints a character to the VGA screen
 * @param c character
 */
void vga_putchar(char c) {
	uint16_t value = c | vga_current_color << 8;
	vga_buffer[vga_row * VGA_WIDTH + vga_column] = value;
	
	if (vga_row == VGA_HEIGHT - 1 && vga_column == VGA_WIDTH - 1) {
		memcpy(vga_buffer, vga_buffer + VGA_WIDTH, sizeof(uint16_t) * VGA_WIDTH * (VGA_HEIGHT - 1));
		memset(vga_buffer + (VGA_WIDTH * (VGA_HEIGHT - 1)), 0, sizeof(uint16_t) * VGA_WIDTH);
		vga_column = 0;
	}
	else if (vga_column == VGA_WIDTH - 1) {
		vga_row++;
		vga_column = 0;
	}
	else {
		vga_column++;
	}
	
	return;
}

/** Moves the VGA cursor
 * @param y new row
 * @param x new column
 */
void vga_move_cursor(size_t y, size_t x) {
	uint16_t location;
	
	location = y * VGA_WIDTH + x;
	
	// Write low byte
	outb(0x0F, 0x3D4);
	outb(0xFF & location, 0x3D5);
	
	// Write high byte
	outb(0x0E, 0x3D4);
	outb(0xFF & (location >> 8), 0x3D5);
	
	return;
}

/** Updates the cursor position to reflect any changes in vga_row and
 * vga_column. Useful after calling vga_putchar() which doesn't do this
 * automatically.
 */
inline void vga_update_cursor() {
	vga_move_cursor(vga_row, vga_column);
	return;
}
