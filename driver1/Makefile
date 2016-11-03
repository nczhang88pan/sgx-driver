ifneq ($(KERNELRELEASE),)
	enclave_ops-y := \
		isgx_enclave_ops.o \
		isgx_ioctl.o \
		isgx_page_cache.o
	obj-m +=enclave_ops.o
else
KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

install: default
	$(MAKE) INSTALL_MOD_DIR=kernel/drivers/intel/sgx -C $(KDIR) M=$(PWD) modules_install
	sh -c "cat /etc/modules | grep -Fxq isgx || echo isgx >> /etc/modules"

endif

clean:
	rm -vrf *.o *.ko *.order *.symvers *.mod.c .tmp_versions .*o.cmd
