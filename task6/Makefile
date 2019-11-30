#CFLAGS_hello.o = -DDEBUG

obj-m += hello.o

#KDIR ?= /lib/modules/$(shell uname -r)/build
#PWD := $(shell pwd)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
