obj-m := hello.o

#KDIR =/usr/src/linux-headers-$(shell uname -r)
KDIR =/lib/modules/$(shell uname -r)/build
all :

	$(MAKE) -C $(KDIR) M=$(PWD) modules
#	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules


clean:

#	rm -rf *.o *.ko *.mod.* *.symvers *.order *.cmd
	$(MAKE) -C $(KDIR) M=$(PWD) clean
#	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean