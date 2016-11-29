#include <linux/module.h>
#include <linux/kernel.h>
int init_module(void)
{
	printk("init enclave ops.\n");
	return 0;
}
void cleanup_module(void)
{
	printk("clean up enclave ops.\n");
}