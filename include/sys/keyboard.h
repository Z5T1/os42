/* Os42
 * 
 * Keyboard Driver
 * File: keyboard.h
 */

/** @file */

#pragma once

#include <stdint.h>

#include <sys/io.h>

/** Represents the current state of the shift key. Do NOT access this
 * value directly.
 */
char kb_key_shift;

/** Represents the current state of the control key. Do NOT access this
 * value directly.
 */
char kb_key_control;

/** Represents the current state of the alt key. Do NOT access this
 * value directly.
 */
char kb_key_alt;

/** Initializes the keyboard driver.
 * This must be called before attempting to use any other part of the
 * keyboard driver.
 */
void kb_init();

