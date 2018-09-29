#include "serial.h"
#include "stringutils.h"

void serial_configure_baud_rate(uint16_t com, uint16_t divisor)
{
	outb(SERIAL_LINE_COMMAND_PORT(com),
			SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com),
			(divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com),
			divisor & 0x00FF);
}

void serial_configure_line(uint16_t com)
{
	outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

int serial_is_transmit_fifo_empty(uint16_t com)
{
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_write(char c, uint16_t com)
{
	while(serial_is_transmit_fifo_empty(com) == 0);

	outb(com, c);
}

void serial_write_string(const char *data)
{
	for(size_t i = 0; i < strlen(data); i++)
	{
		serial_write(data[i], SERIAL_COM1_BASE);
	}
}
