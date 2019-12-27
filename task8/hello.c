#include <linux/module.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>
#include <linux/debugfs.h>
#include <linux/jiffies.h>
#include <linux/semaphore.h>

#define MY_ID "netoeuler666\n"
#define MY_ID_LEN 13	/* MY_ID length */

static DEFINE_SEMAPHORE(foo_sem);

static char foo_data[PAGE_SIZE];
static int foo_len;
static struct dentry *eudy;

static ssize_t foo_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
	int retval = -EINVAL;

	if (*ppos != 0)
		return 0;

	down(&foo_sem);

	if (!copy_to_user(buf, foo_data, foo_len)) {
		*ppos += count;
		retval = count;
	}

	up(&foo_sem);
	return retval;
}

static ssize_t foo_write(struct file *file, char const __user *buf,
			size_t count, loff_t *ppos)
{
	int retval = -EINVAL;

	if (count >= PAGE_SIZE)
		return -EINVAL;

	down(&foo_sem);

	if (copy_from_user(foo_data, buf, count)) {
		foo_len = 0;
	} else {
		foo_len = count;
		retval = count;
	}

	up(&foo_sem);
	return retval;
}

static const struct file_operations foo_fops = {
	.owner = THIS_MODULE,
	.read = foo_read,
	.write = foo_write
};

static ssize_t id_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
	char *hello_str = MY_ID;

	if (*ppos != 0)
		return 0;

	if ((count < MY_ID_LEN) ||
		(copy_to_user(buf, hello_str, MY_ID_LEN)))
		return -EINVAL;

	*ppos += count;
	return count;
}

static ssize_t id_write(struct file *file, char const __user *buf,
			size_t count, loff_t *ppos)
{
	char *hello_str = MY_ID;
	char input[MY_ID_LEN];

	if ((count != MY_ID_LEN) ||
		(copy_from_user(input, buf, MY_ID_LEN)) ||
		(strncmp(hello_str, input, MY_ID_LEN)))
		return -EINVAL;
	else
		return count;
}

static const struct file_operations id_fops = {
	.owner = THIS_MODULE,
	.read = id_read,
	.write = id_write
};

static int __init hello_init(void)
{
	eudy = debugfs_create_dir("eudyptula", NULL);
	if (!eudy)
		goto fail;

	if (!debugfs_create_file("foo", 0644, eudy, NULL, &foo_fops))
		goto fail;

	if (!debugfs_create_u32("jiffies", 0444, eudy, (u32*)&jiffies))
		goto fail;

	if (!debugfs_create_file("id", 0666, eudy, NULL, &id_fops))
		goto fail;

	pr_debug("Hello Task8!\n");
	foo_len = 0;
	return 0;

fail:	pr_alert("Could not create devices");
	return -ENODEV;
}

static void __exit hello_exit(void)
{
	debugfs_remove_recursive(eudy);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("netoeuler");
MODULE_DESCRIPTION("task8 module");
