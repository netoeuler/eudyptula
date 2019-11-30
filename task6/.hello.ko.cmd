cmd_/root/task6/hello.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds  --build-id  -o /root/task6/hello.ko /root/task6/hello.o /root/task6/hello.mod.o ;  true
