/* Os42
 * 
 * Standard Library
 * File: stdlib.c
 */

#include <stdlib.h>

/** The  memcpy()  function  copies  n bytes from memory area src to
 * memory area dest.
 * Care should be used if the memory areas overlap. In this case, memcpy
 * only works as intended if src is before dest.
 */
void* memcpy(void* dest, const void* src, size_t n) {
	size_t i;
	
	for (i = 0; i < n; i++) {
		((uint8_t*) dest)[i] = ((uint8_t*) src)[i];
	}
	
	return dest;
}

/** The  memset()  function  fills  the  first  n  bytes of the memory
 * area pointed to by s with the constant byte c.
 */
void* memset(void* s, uint8_t c, size_t n) {
	size_t i;
	
	for (i = 0; i < n; i++) {
		((uint8_t*) s)[i] = c;
	}
	
	return s;
}
