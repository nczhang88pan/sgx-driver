
#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_ALERT */
int init_module(void)
{
   printk(KERN_ALERT "init enclave ops.\n");
   return 0;
}

void cleanup_module(void)
{
  printk(KERN_ALERT "clean up enclave ops.\n");
}  

int test(void)
{
	printk("driver1:this is test\n");
}
EXPORT_SYMBOL(test);

