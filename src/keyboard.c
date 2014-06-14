/* Os42
 * 
 * Keyboard Driver
 * File: keyboard.c
 */

#include <keyboard.h>

/** Initializes the keyboard driver.
 * This must be called before attempting to use any other part of the
 * keyboard driver.
 */
void kb_init() {
	// Variable Initialization
	kb_key_shift = 0;
	kb_key_control = 0;
	kb_key_alt = 0;
	
	return;
}
