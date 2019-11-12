#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("netoeuler");
MODULE_DESCRIPTION("Writing kernel modules. First blood!");

static int __init hello_init(void){
	printk(KERN_INFO "Hell yeah!\n");
	return 0;
}

static void __exit hello_cleanup(void){
	printk(KERN_INFO "Cleaning out my closet...\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
