today=`date +%Y-%m-%d.%H:%M:%S`

qemu-system-x86_64 -serial file:../logs/$today.out  -kernel kernel.elf
