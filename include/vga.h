/* Os42
 * 
 * VGA Driver
 * File: vga.h
 */

/** @file */

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <stdlib.h>
#include <sys/io.h>

/** Defines constants for VGA colors */
typedef enum {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_YELLOW = 14,
	COLOR_WHITE = 15
} vga_color;

/** The width of the VGA screen */
#define VGA_WIDTH 80

/** The height of the VGA screen */
#define VGA_HEIGHT 25

/** The VGA output buffer.
 * This value should not be accessed directly; that kind of defeats
 * the whole purpose of this library ;)
 */
uint16_t* vga_buffer;

/** The current VGA color settings.
 * This generally should not be accessed directly, but rather should
 * make use of the vga_set_color(), vga_set_fg(), vga_set_bg(),
 * vga_get_fg() and vga_get_bg() functions.
 */
uint8_t vga_current_color;

/** The current VGA display row.
 * This value should not be accessed directly.
 */
size_t vga_row;

/** The current VGA display column.
 * This value should not be accessed directly.
 */
size_t vga_column;

/** Initializes the VGA driver.
 * This must be called before attempting to use any other part of the
 * VGA driver.
 */
void vga_init();

/** Sets the VGA foreground color
 * @param color the new foreground color
 */
void vga_set_fg(vga_color color);

/** Sets the VGA background color
 * @param color the new background color
 */
void vga_set_bg(vga_color color);

/** Sets the VGA foreground and background colors
 * @param fg the new foreground color
 * @param bg the new background color
 */
void vga_set_color(vga_color fg, vga_color bg);

/** Gets the current VGA foreground color
 * @return the current foreground color
 */
vga_color vga_get_fg();

/** Gets the current VGA background color
 * @return the current background color
 */
vga_color vga_get_bg();

/** Prints a character to the VGA screen. This does NOT update the
 * cursor position, use vga_update_cursor() for that.
 * @param c character
 */
void vga_putchar(char c);

/** Moves the VGA cursor
 * @param y new row
 * @param x new column
 */
void vga_move_cursor(size_t y, size_t x);

/** Updates the cursor position to reflect any changes in vga_row and
 * vga_column. Useful after calling vga_putchar() which doesn't do this
 * automatically.
 */
inline void vga_update_cursor();
