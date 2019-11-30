#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>

static ssize_t hello_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos){
	if (*ppos != 0)
		return 0;

	if ((count < 13) || (copy_to_user(buf,"netoeuler666",13)))
		return -EINVAL;

	*ppos += count;
	return count;
}

static ssize_t hello_write(struct file *file, char const __user *buf,
			size_t count, loff_t *pops){
	char input[13];

	if ((count != 13) || (copy_from_user(input, buf, 13)) ||
		(strncmp("netoeuler666", input, 13 - 1)))
		return -EINVAL;
	else
		return count;
}

static const struct file_operations hello_fops = {
	.owner = THIS_MODULE,
	.read = hello_read,
	.write = hello_write
};

static struct miscdevice hello_dev = {
	MISC_DYNAMIC_MINOR,
	"eudyptula",
	&hello_fops
};

static int __init hello_init(void){
	int ret;

	ret = misc_register(&hello_dev);
	pr_debug("Hello world!\n");

	return ret;
}

static void __exit hello_exit(void){
	misc_deregister(&hello_dev);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("netoeuler666");
MODULE_DESCRIPTION("Task6 module");
