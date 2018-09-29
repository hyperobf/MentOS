cp build/kernel.elf build/isodir/boot/kernel.elf
grub-mkrescue -o build/MentOS.iso build/isodir
