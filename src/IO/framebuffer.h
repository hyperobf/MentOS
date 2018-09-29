#ifndef __MENTOS_FRAMEBUFFER_H
#define __MENTOS_FRAMEBUFFER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "stringutils.h"

#define FRAMEBUFFER_COMMAND_PORT	0x3D4
#define FRAMEBUFFER_DATA_PORT		0x3D5
#define FRAMEBUFFER_HIGH_BYTE_CMD	14
#define FRAMEBUFFER_LOW_BYTE_CMD	15

/*
 * The dimensions of the terminal
 */
static const size_t VGA_HEIGHT = 25;
static const size_t VGA_WIDTH = 80;


/*
 * Framebuffer color constants
 */
enum framebuffer_color
{
	FB_BLACK	= 0,
	FB_BLUE		= 1,
	FB_GREEN 	= 2,
	FB_CYAN 	= 3,
	FB_RED		= 4,
	FB_MAGENTA	= 5,
	FB_BROWN	= 6,
	FB_LGRAY	= 7,
	FB_DGRAY	= 8,
	FB_LBLUE	= 9,
	FB_LGREEN	= 10,
	FB_LCYAN	= 11,
	FB_LRED		= 12,
	FB_LMAGENTA = 13,
	FB_LBROWN	= 14,
	FB_WHITE	= 15
};

/* framebuffer_write_cell:
 * Writes a character with the given foreground and background to positoin
 * i in the framebuffer.
 *
 * @param i		the location in the framebuffer
 * @param c		the character
 * @param fg	the foreground
 * @param bg	the background
 */
void framebuffer_write_cell(size_t i, char c, enum framebuffer_color fg, enum framebuffer_color bg);

/* framebuffer_write_string:
 * Writes the given string to the framebuffer
 *
 * @param data 	the string to write
 */
void framebuffer_write_string(const char *data);

/* framebuffer_clear:
 * Clears the terminal screen
 */
void framebuffer_clear();

/* framebuffer_scroll:
 * Scrolls the screen by 1
 */
void framebuffer_scroll();

/* outb:
 * Sends the given data to the given I/O port. Defined in IO.asm
 * 
 * @param port 	The I/O port to send the data to
 * @param data	The data to send to the I/O port
 */
void outb(unsigned short port, unsigned char data);

/* framebuffer_move_cursor:
 * Moves the cursor of the framebuffer to the given position
 *
 * @param pos	The new position of the cursor
 */
void framebuffer_move_cursor(unsigned short pos);

/* framebuffer_cursor_xy:
 * Moves the cursor to position with coordinates
 *
 * @param x		The x coordinate
 * @param y		The y coordinate
 */
void framebuffer_cursor_xy(size_t x, size_t y);

#endif
