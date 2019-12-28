cmd_/root/task9/hello.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds  --build-id  -o /root/task9/hello.ko /root/task9/hello.o /root/task9/hello.mod.o ;  true
