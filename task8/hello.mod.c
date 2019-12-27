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
	{ 0x90e4fd8b, "debugfs_remove_recursive" },
	{ 0xc5850110, "printk" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1749a63d, "debugfs_create_u32" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xb353c3f2, "debugfs_create_file" },
	{ 0xff2ead68, "debugfs_create_dir" },
	{ 0xcf2a6966, "up" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6626afca, "down" },
	{ 0x56470118, "__warn_printk" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "DC73B88392CE7C55CA67D0A");
