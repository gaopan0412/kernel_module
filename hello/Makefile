KERNEL := /home/gaopan/src/linux-3.19.3
PWD := $(shell pwd)
obj-m  := hello.o

all:
	$(MAKE) -C ${KERNEL} M=$(PWD) modules
clean:
	rm -rf *.mod.* *.o *.order *.symvers *.ko .hello.* .tmp*
	
