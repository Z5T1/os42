/* Os42
 * 
 * Input / Output Library
 * File: io.h
 */

/** @file */

#pragma once

#include <stdint.h>

/** Writes a byte value to a serial port 
 * @param value value to write
 * @param port port to write to
 */
void outb(uint8_t value, uint16_t port);

/** Reads a byte from a serial port
 * @param port port to read from
 * @return byte read
 */
uint8_t inb(uint16_t port);
