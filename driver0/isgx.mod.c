#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xcb9fb324, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x8487a2b6, __VMLINUX_SYMBOL_STR(flush_work) },
	{ 0x50b01722, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x3356b90b, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0x2a96c65b, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xa8d92fee, __VMLINUX_SYMBOL_STR(put_pid) },
	{ 0x515de01c, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x4c4f1833, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x1385d796, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x9731ccab, __VMLINUX_SYMBOL_STR(set_page_dirty) },
	{ 0x5e7fcb35, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x34a01540, __VMLINUX_SYMBOL_STR(__mmdrop) },
	{ 0xec25b331, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xece784c2, __VMLINUX_SYMBOL_STR(rb_first) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xf4afebc1, __VMLINUX_SYMBOL_STR(__init_work) },
	{ 0xf032ca49, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x4c62fd7, __VMLINUX_SYMBOL_STR(__memset) },
	{ 0xafc86d99, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xecac8407, __VMLINUX_SYMBOL_STR(__memcpy) },
	{ 0x9ab87056, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xedaccfb1, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x3003a182, __VMLINUX_SYMBOL_STR(apply_to_page_range) },
	{ 0xfe3faaea, __VMLINUX_SYMBOL_STR(shmem_read_mapping_page_gfp) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x4d9b652b, __VMLINUX_SYMBOL_STR(rb_erase) },
	{ 0x9cc4f70a, __VMLINUX_SYMBOL_STR(register_pm_notifier) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xa0f5fd67, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x93fa571e, __VMLINUX_SYMBOL_STR(fput) },
	{ 0xcd1e65c1, __VMLINUX_SYMBOL_STR(shmem_file_setup) },
	{ 0xf11543ff, __VMLINUX_SYMBOL_STR(find_first_zero_bit) },
	{ 0x44df11a5, __VMLINUX_SYMBOL_STR(find_vma) },
	{ 0xf266c53d, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0xd75c79df, __VMLINUX_SYMBOL_STR(smp_call_function) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xc0cd3b13, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0xc126ccc7, __VMLINUX_SYMBOL_STR(pv_cpu_ops) },
	{ 0x5120cea4, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xcc5005fe, __VMLINUX_SYMBOL_STR(msleep_interruptible) },
	{ 0xd0c055fc, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xa5526619, __VMLINUX_SYMBOL_STR(rb_insert_color) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0xf842435d, __VMLINUX_SYMBOL_STR(zap_vma_ptes) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x3bb5114a, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0xaec0599b, __VMLINUX_SYMBOL_STR(pv_mmu_ops) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0x68c7263, __VMLINUX_SYMBOL_STR(ioremap_cache) },
	{ 0x7681946c, __VMLINUX_SYMBOL_STR(unregister_pm_notifier) },
	{ 0x5ed51166, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xca9360b5, __VMLINUX_SYMBOL_STR(rb_next) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x655e076a, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0x21dffd, __VMLINUX_SYMBOL_STR(vm_insert_pfn) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E178E1486246091E5BAB709");
