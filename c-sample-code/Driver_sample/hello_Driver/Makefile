obj-m := hello.o

KDIR =/usr/src/linux-headers-$(shell uname -r)

all :

	$(MAKE) -C $(KDIR) M=$(PWD) modules
#	rm $(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules


clean:

	rm -rf *.o *.ko *.mod *.symvers *.order
#	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean