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
	
	return;
}

/** Reads a byte from a serial port
 * @param port port to read from
 * @return byte read
 */
uint8_t inb(uint16_t port) {
	uint16_t ret;
	
	asm volatile (
		"\tinb %1, %0\n"
		: "=a"(ret) : "d"(port)
	);
	
	return ret;
}
