#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4d797a9f, "module_layout" },
	{ 0x464408c8, "kmem_cache_destroy" },
	{ 0x9dfb7677, "kmem_cache_create" },
	{ 0x79f9f409, "kmem_cache_free" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x9166fada, "strncpy" },
	{ 0xa300b6e2, "kmem_cache_alloc_trace" },
	{ 0xe5d15ec8, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "523EB53112353C163D1045B");
