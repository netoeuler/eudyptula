cmd_/root/task1/hello.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /root/task1/hello.ko /root/task1/hello.o /root/task1/hello.mod.o
