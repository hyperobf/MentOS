#include "interrupt.h"

#include "../IO/framebuffer.h"
#include "../IO/serial.h"
#include "idt.h"
#include "pic.h"

#define SYSCALL_INT_IDX 0xAE

static interrupt_handler_t interrupt_handlers[IDT_NUM_ENTRIES];

uint32_t register_interrupt_handler(uint32_t interrupt,
									interrupt_handler_t handler)
{
	if (interrupt > 255)
	{
		return 1;
	}
	if (interrupt == SYSCALL_INT_IDX)
	{
		return 1;
	}
	if (interrupt_handlers[interrupt] != NULL)
	{
		return 1;
	}

	interrupt_handlers[interrupt] = handler;
	return 0;
}

void interrupt_handler(cpu_state_t state, idt_info_t info, stack_state_t exec)
{
	serial_write_string("interrupt handled \n");
	framebuffer_write_string("interrupt handled \n");

	if (interrupt_handlers[info.idt_index] != NULL) {
		interrupt_handlers[info.idt_index](state, info, exec);
    } else {
    	/*serial_write(,
			"unhandled interrupt: %u, eip: %X, cs: %X, eflags: %X\n",
                  info.idt_index, exec.eip, exec.cs, exec.eflags);*/
    }if (interrupt_handlers[info.idt_index] != NULL) {
        interrupt_handlers[info.idt_index](state, info, exec);
    } else {
        /*log_info("interrupt_handler",
                  "unhandled interrupt: %u, eip: %X, cs: %X, eflags: %X\n",
                  info.idt_index, exec.eip, exec.cs, exec.eflags);*/
    }
}
