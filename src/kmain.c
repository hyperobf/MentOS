#include "IO/framebuffer.h"
#include "IO/serial.h"

void kmain(void)
{
	framebuffer_clear();
	framebuffer_write_string("MentOS Version 0.1\n");
	serial_write_string("MentOS Version 0.1\n");

	framebuffer_cursor_xy(5, 5);
}
