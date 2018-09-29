#include "IO/framebuffer.h"
#include "IO/serial.h"
#include "memory/gdt.h"
#include "memory/pic.h"
#include "memory/interrupt.h"
#include "memory/idt.h"

void log(const char *data)
{
	framebuffer_write_string(data);
	serial_write_string(data);
}

void kmain(void)
{
	framebuffer_clear();
	log("MentOS Version 0.01\n");
	log("Loading...\n");
	log("Intializing GDT... ");
	init_gdt();
	log("done\n");

	idt_init();
	pic_init();

	enable_interrupts();

	framebuffer_cursor_xy(5, 5);
}
