/* Os42
 * 
 * Input / Output Library
 * File: io.c
 */

#include <sys/io.h>

/** Writes a byte value to a serial port 
 * @param value value to write
 * @param port port to write to
 */
void outb(uint8_t value, uint16_t port) {
	asm volatile (
		"\toutb %0, %1\n"
		:: "r"(value), "r"(port)
	);
}
