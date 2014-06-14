/* Os42
 * 
 * Standard Input / Output Library
 * File: stdio.h
 */

/** @file */

#pragma once

#include <sys/vga.h>

/** Prints a character to the screen
 * @param c character to print
 */
void putc(char c);

/** Prints a string to the screen
 * @param s string to print
 */
void puts(char* s);

/** Prints an integer to the screen
 * @param d integer to print
 */
void puti(uint32_t d);

/** Prints an integer to the screen in hexadecimal
 * @param d integer to print
 */
void puth(uint32_t d);
