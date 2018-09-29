#ifndef __MENTOS_IO_H
#define __MENTOS_IO_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* outb:
 * Sends the given data to the given I/O port. Defined int io.asm
 *
 * @param port	The I/O port to send the data to
 * @param data	The data to send the I/O port
 */
void outb(uint16_t port, uint16_t data);

/* inb:
 * Reads a byte from the I/O port
 *
 * @param port 	The address of the I/O port
 * @return		The read byte
 */

uint8_t inb(uint16_t port);

#endif
