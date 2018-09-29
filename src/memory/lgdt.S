global load_gdt
load_gdt:
	mov eax, [esp + 4]
	lgdt [eax]
	ret

	; the jmp to 0x08 will load the CS register
	jmp 0x08:.reload_segments

.reload_segments
	; one segment for data
	mov ax, 0x10
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov gs, ax
	mov fs, ax
	ret

