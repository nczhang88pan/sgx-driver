/*
 * (C) Copyright 2015 Intel Corporation
 *
 * Authors:
 *
 * Jarkko Sakkinen <jarkko.sakkinen@intel.com>
 * Suresh Siddha <suresh.b.siddha@intel.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include "isgx.h"
#include <linux/acpi.h>
#include <linux/compat.h>
#include <linux/file.h>
#include <linux/highmem.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/suspend.h>
#include <linux/hashtable.h>
#include <linux/kthread.h>

#define DRV_DESCRIPTION "Intel SGX Driver"
#define DRV_VERSION "0.10"

#define ENCLAVE_SIZE_MAX_64 (64ULL * 1024ULL * 1024ULL * 1024ULL)
#define ENCLAVE_SIZE_MAX_32 (2ULL * 1024ULL * 1024ULL * 1024ULL)

MODULE_DESCRIPTION(DRV_DESCRIPTION);
MODULE_AUTHOR("Jarkko Sakkinen <jarkko.sakkinen@intel.com>");
MODULE_VERSION(DRV_VERSION);

/*
 * Global data.
 */

struct workqueue_struct *isgx_add_page_wq;
resource_size_t isgx_epc_base = 0;
unsigned long isgx_epc_size = 0;
#ifdef CONFIG_X86_64
void *isgx_epc_mem;
#endif
u64 isgx_enclave_size_max_32 = ENCLAVE_SIZE_MAX_32;
u64 isgx_enclave_size_max_64 = ENCLAVE_SIZE_MAX_64;
u64 isgx_xfrm_mask = 0x3;
u32 isgx_ssaframesize_tbl[64];

/*
 * Local data.
 */


// static int isgx_mmap(struct file *file, struct vm_area_struct *vma);

// static unsigned long isgx_get_unmapped_area(struct file *file,
// 					    unsigned long addr,
// 					    unsigned long len,
// 					    unsigned long pgoff,
// 					    unsigned long flags);

// #ifdef CONFIG_COMPAT
// static long isgx_compat_ioctl(struct file *filep, unsigned int cmd,
// 			     unsigned long arg)
// {
// 	return isgx_ioctl(filep, cmd, arg);
// }
// #endif

// static const struct file_operations isgx_fops = {
// 	.owner		= THIS_MODULE,
// 	.unlocked_ioctl	= isgx_ioctl,
// #ifdef CONFIG_COMPAT
// 	.compat_ioctl	= isgx_compat_ioctl,
// #endif
// 	.mmap		= isgx_mmap,
// 	.get_unmapped_area = isgx_get_unmapped_area,
// };

// static struct miscdevice isgx_dev = {
// 	.name	= "isgx",
// 	.fops	= &isgx_fops,
// 	.mode   = S_IRUGO | S_IWUGO,
// };

// static int isgx_power_event(struct notifier_block *this, unsigned long event,
// 			    void *ptr);


// static struct notifier_block isgx_pm_notifier = {
// 	.notifier_call = isgx_power_event,
// };

// static int isgx_mmap(struct file *file, struct vm_area_struct *vma)
// {
// 	vma->vm_ops = &isgx_vm_ops;
// #if !defined(VM_RESERVED)
// 	vma->vm_flags |= VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP | VM_IO;
// #else
// 	vma->vm_flags |= VM_PFNMAP | VM_DONTEXPAND | VM_RESERVED | VM_IO;
// #endif

// 	return 0;
// }

// static void __isgx_enable_in_cr4(void *v)
// {
// #if 0
// 	write_cr4(read_cr4() | (1 << 15));
// #endif
// }

// static void isgx_enable(void)
// {
// 	__isgx_enable_in_cr4(NULL);
// 	smp_call_function(__isgx_enable_in_cr4, NULL, 1);
// }

// static void __isgx_disable_in_cr4(void *v)
// {
// #if 0
// 	write_cr4(read_cr4() & ~(1 << 15));
// #endif
// }

// /* Should be in arch/x86/include/asm/cpufeature.h when upstreamed. */
// #ifndef X86_FEATURE_SGX
// #define X86_FEATURE_SGX (9 * 32 + 2)
// #endif



static int isgx_init_iso(resource_size_t epc_base, unsigned long epc_size)
{
	int ret;
	isgx_epc_base = epc_base;
	isgx_epc_size = epc_size;
	
#ifdef CONFIG_X86_64
	isgx_epc_mem = ioremap_cache(isgx_epc_base, isgx_epc_size);
	if (!isgx_epc_mem)
		return -ENOMEM;
#endif

	ret = isgx_page_cache_init_iso(isgx_epc_base, isgx_epc_size);
	if (ret)
		goto out_iounmap;

	// isgx_enable();
	pr_info("%s: done\n", __func__);
	return 0;

out_iounmap:
#ifdef CONFIG_X86_64
	iounmap(isgx_epc_mem);
#endif
	return ret;
}
EXPORT_SYMBOL(isgx_init_iso);

static void isgx_exit_iso(void)
{
#ifdef CONFIG_X86_64
	iounmap(isgx_epc_mem);
#endif
	 isgx_page_cache_teardown_iso();

	// __isgx_disable_in_cr4(NULL);
	// smp_call_function(__isgx_disable_in_cr4, NULL, 1);
	 pr_info("%s: done\n", __func__);
}
EXPORT_SYMBOL(isgx_exit_iso);
// static unsigned long isgx_get_unmapped_area(struct file *file,
// 					   unsigned long addr,
// 					   unsigned long len,
// 					   unsigned long pgoff,
// 					   unsigned long flags)
// {

// 	if (len < 2 * PAGE_SIZE || (len & (len - 1)))
// 		return -EINVAL;

// 	/* On 64-bit architecture, allow mmap() to exceed 32-bit enclave
// 	 * limit only if the task is not running in 32-bit compatibility
// 	 * mode.
// 	 */
// 	if (len > isgx_enclave_size_max_32)
// #ifdef CONFIG_X86_64
// 		if (test_thread_flag(TIF_ADDR32))
// 			return -EINVAL;
// #else
// 		return -EINVAL;
// #endif

// #ifdef CONFIG_X86_64
// 	if (len > isgx_enclave_size_max_64)
// 		return -EINVAL;
// #endif

// 	addr = current->mm->get_unmapped_area(file, addr, 2*len, pgoff, flags);

// 	if (IS_ERR_VALUE(addr))
// 		return addr;

// 	addr = (addr + (len - 1)) & ~(len - 1);

// 	return addr;
// }

// static int isgx_suspend(void)
// {
// 	struct isgx_tgid_ctx *ctx;
// 	struct isgx_enclave *encl;

// 	kthread_stop(kisgxswapd_tsk);
// 	kisgxswapd_tsk = NULL;

// 	list_for_each_entry(ctx, &isgx_tgid_ctx_list, list) {
// 		list_for_each_entry(encl, &ctx->enclave_list, enclave_list) {
// 			isgx_invalidate(encl);
// 			encl->flags |= ISGX_ENCLAVE_SUSPEND;
// 		}
// 	}

// 	return NOTIFY_OK;
// }

// static int isgx_resume(void)
// {
// 	pr_info("isgx: resume\n");

// 	isgx_enable();
// 	kisgxswapd_tsk = kthread_run(kisgxswapd, NULL, "kisgxswapd");

// 	return NOTIFY_OK;
// }

// static int isgx_power_event(struct notifier_block *this, unsigned long event,
// 			    void *ptr)
// {
//         switch (event) {
//         case PM_POST_HIBERNATION:
//         case PM_POST_SUSPEND:
//                 return isgx_resume();
//         case PM_HIBERNATION_PREPARE:
//         case PM_SUSPEND_PREPARE:
//                 return isgx_suspend();
//         default:
//                 return NOTIFY_DONE;
//         }
// }

MODULE_LICENSE("GPL");
