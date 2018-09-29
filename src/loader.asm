MAGIC_NUMBER	equ 0x1BADB002
MBALIGN			equ 1 << 0
MEMINFO			equ 1 << 1
FLAGS			equ MBALIGN | MEMINFO
CHECKSUM		equ -(MAGIC_NUMBER + FLAGS)
STACK_SIZE		equ 16384

section .multiboot
align 4
	dd MAGIC_NUMBER
	dd FLAGS
	dd CHECKSUM

section .bss
align 16
stack_bottom:
resb STACK_SIZE
stack_top:

section .text
global _start:function (_start.end - _start)
_start:
	mov esp, stack_top
	
	extern kmain
	call kmain

	cli
.loop:
	hlt
	jmp .loop
.end:
