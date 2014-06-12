/* Os42
 * 
 * Standard Library
 * File: stdlib.h
 */

/** @file */

#pragma once

#include <stddef.h>
#include <stdint.h>

/** The  memcpy()  function  copies  n bytes from memory area src to
 * memory area dest.
 * Care should be used if the memory areas overlap. In this case, memcpy
 * only works as intended if src is before dest.
 */
void* memcpy(void* dest, const void* src, size_t n);

/** The  memset()  function  fills  the  first  n  bytes of the memory
 * area pointed to by s with the constant byte c.
 */
void* memset(void* s, uint8_t c, size_t n);
