cmd_/root/task13/hello.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds  --build-id  -o /root/task13/hello.ko /root/task13/hello.o /root/task13/hello.mod.o ;  true
