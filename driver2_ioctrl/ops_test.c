
#include "isgx.h"
#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_ALERT */
#include <linux/acpi.h>
#include <linux/compat.h>
#include <linux/file.h>
#include <linux/highmem.h>
#include <linux/miscdevice.h>
#include <linux/suspend.h>
#include <linux/hashtable.h>
#include <linux/kthread.h>
#include "ops_test.h"
//#include "../driver1_withinIso/enclave_ops.h"
static int __init isgx_init(void)
{
   	test();
   	printk(KERN_ALERT "init ops_test.\n");


   	//unsigned int wq_flags;
	int ret;

	pr_info("isgx: " DRV_DESCRIPTION " v" DRV_VERSION "\n");

	if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
		return -ENODEV;

	ret = isgx_init_platform();
// 	if (ret)
// 		return ret;

// 	pr_info("isgx: EPC memory range 0x%Lx-0x%Lx\n", isgx_epc_base,
// 		isgx_epc_base + isgx_epc_size);

// #ifdef CONFIG_X86_64
// 	isgx_epc_mem = ioremap_cache(isgx_epc_base, isgx_epc_size);
// 	if (!isgx_epc_mem)
// 		return -ENOMEM;
// #endif

// 	ret = isgx_page_cache_init(isgx_epc_base, isgx_epc_size);
// 	if (ret)
// 		goto out_iounmap;

// 	wq_flags = WQ_UNBOUND | WQ_FREEZABLE;
// #ifdef WQ_NON_REENETRANT
// 	wq_flags |= WQ_NON_REENTRANT;
// #endif
// 	isgx_add_page_wq = alloc_workqueue("isgx-add-page-wq", wq_flags, 1);
// 	if (!isgx_add_page_wq) {
// 		pr_err("isgx: alloc_workqueue() failed\n");
// 		ret = -ENOMEM;
// 		goto out_iounmap;
// 	}

// 	ret = misc_register(&isgx_dev);
// 	if (ret) {
// 		pr_err("isgx: misc_register() failed\n");
// 		goto out_workqueue;
// 	}

// 	ret = register_pm_notifier(&isgx_pm_notifier);
// 	if (ret) {
// 		pr_err("isgx: register_pm_notifier() failed\n");
// 		goto out_misc;
// 	}

// 	isgx_enable();

// 	return 0;
// out_misc:
// 	misc_deregister(&isgx_dev);
// out_workqueue:
// 	destroy_workqueue(isgx_add_page_wq);
// out_iounmap:
// #ifdef CONFIG_X86_64
// 	iounmap(isgx_epc_mem);
// #endif
// 	return ret;
   return 0;
}
static int isgx_init_platform(void)
{
	unsigned int eax, ebx, ecx, edx;
	int i;

	cpuid(0, &eax, &ebx, &ecx, &edx);
	if (eax < SGX_CPUID) {
		pr_err("isgx: CPUID is missing the SGX leaf instruction\n");
		return -ENODEV;
	}

	if (!boot_cpu_has(X86_FEATURE_SGX)) {
		pr_err("isgx: CPU is missing the SGX feature\n");
		return -ENODEV;
	}

	cpuid_count(SGX_CPUID, 0x0, &eax, &ebx, &ecx, &edx);
	if (!(eax & 1)) {
		pr_err("isgx: CPU does not support the SGX 1.0 instruction set\n");
		return -ENODEV;
	}

	if (boot_cpu_has(X86_FEATURE_OSXSAVE)) {
		cpuid_count(SGX_CPUID, 0x1, &eax, &ebx, &ecx, &edx);
		isgx_xfrm_mask = (((u64) edx) << 32) + (u64) ecx;
		for (i = 2; i < 64; i++) {
			cpuid_count(0x0D, i, &eax, &ebx, &ecx, &edx);
			if ((1 << i) & isgx_xfrm_mask)
				isgx_ssaframesize_tbl[i] =
					(168 + eax + ebx + PAGE_SIZE - 1) /
					PAGE_SIZE;
		}
	}

	cpuid_count(SGX_CPUID, 0x0, &eax, &ebx, &ecx, &edx);
	if (edx & 0xFFFF) {
#ifdef CONFIG_X86_64
		isgx_enclave_size_max_64 = 1ULL << ((edx >> 8) & 0xFF);
#endif
		isgx_enclave_size_max_32 = 1ULL << (edx & 0xFF);
	}

	cpuid_count(SGX_CPUID, 0x2, &eax, &ebx, &ecx, &edx);

	/* The should be at least one EPC area or something is wrong. */
	BUG_ON((eax & 0xf) != 0x1);
	isgx_epc_base = (((u64) (ebx & 0xfffff)) << 32) +
		(u64) (eax & 0xfffff000);
	isgx_epc_size = (((u64) (edx & 0xfffff)) << 32) +
		(u64) (ecx & 0xfffff000);

	if (!isgx_epc_base)
		return -ENODEV;

	return 0;
}
static void __exit isgx_exit(void)
{
  printk(KERN_ALERT "clean up ops_test.\n");
}  

module_init(isgx_init);
module_exit(isgx_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Someone Like You");
