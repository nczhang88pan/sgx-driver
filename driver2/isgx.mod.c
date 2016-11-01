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
	{ 0x2a96c65b, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xe8f5785e, __VMLINUX_SYMBOL_STR(__eblock) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x3a30b44b, __VMLINUX_SYMBOL_STR(__etrack) },
	{ 0x4c4f1833, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x1385d796, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x9731ccab, __VMLINUX_SYMBOL_STR(set_page_dirty) },
	{ 0x5e7fcb35, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xafc86d99, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x6e2ae2d8, __VMLINUX_SYMBOL_STR(__ewb) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xedaccfb1, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xa0f5fd67, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xaaabc306, __VMLINUX_SYMBOL_STR(test) },
	{ 0xd75c79df, __VMLINUX_SYMBOL_STR(smp_call_function) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xc0cd3b13, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0x5120cea4, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xd0c055fc, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0xf842435d, __VMLINUX_SYMBOL_STR(zap_vma_ptes) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x3bb5114a, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x5ed51166, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=enclave_ops";


MODULE_INFO(srcversion, "18E2B3F3C2EA44767882668");
