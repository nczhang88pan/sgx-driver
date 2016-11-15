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
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x4c4f1833, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0xabfa3d75, __VMLINUX_SYMBOL_STR(construct_enclave_page) },
	{ 0xf032ca49, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x4c62fd7, __VMLINUX_SYMBOL_STR(__memset) },
	{ 0xafc86d99, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0xeda16ce5, __VMLINUX_SYMBOL_STR(isgx_page_cache_init) },
	{ 0xaaabc306, __VMLINUX_SYMBOL_STR(test) },
	{ 0x5f3e1c5e, __VMLINUX_SYMBOL_STR(__ecreate) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xd0c055fc, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=enclave_ops";


MODULE_INFO(srcversion, "5AC0F3EC64FE4A102708FB8");
