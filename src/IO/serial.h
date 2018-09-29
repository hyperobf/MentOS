#ifndef __MENTOS_SERIAL_H
#define __MENTOS_SERIAL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "io.h"

/* 
 * The I/O ports
 *
 * The I/O ports are calculated relative to the data port.
 */
#define SERIAL_COM1_BASE				0x3F8

#define SERIAL_DATA_PORT(base)			(base)
#define SERIAL_FIFO_COMMAND_PORT(base)	(base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base)	(base + 4)
#define SERIAL_LINE_STATUS_PORT(base)	(base + 5)

/*
 * Tells the serial port to expect the highest 8 bits, then the lowest 8 bits
 */
#define SERIAL_LINE_ENABLE_DLAB			0x80

/* serial_configure_baud_rate:
 * set the speed of sending data (baud rate). The default speed of a serial
 * port is 115200 bits/s. This will divide that by the divisor here
 *
 * @param com		The com port to configure
 * @param divisor	What to divide the number by
 */
void serial_configure_baud_rate(uint16_t com, uint16_t divisor);

/* serial_configure_line:
 * Configures the line of a given port. We will use 0x03 meaning a length of
 * 8 bits, no parity bit, one stop bit and break control disabled.
 *
 * @param com 	The COM port to configure
 */
void serial_configure_line(uint16_t com);

/* serial_is_transmit_fifo_empty
 * Checks if the transmit FIFO queue is empty or not for the given COM port
 *
 * @param com		The COM port
 * @param return	0 if the transmit FIFO port is not empty
 * 					1 if the transmit FIFO port is empty
 */
int serial_is_transmit_fifo_empty(uint16_t com);

/* serial_write:
 * Writes a char to serial
 * 
 * @param c			The char to write to serial
 * @param com		The COM port to write to
 */
void serial_write(char c, uint16_t com);

/* serial_write_string:
 * Writes a string to serial
 *
 * @param data		The string to write to serial
 */
void serial_write_string(const char *data);

#endif
