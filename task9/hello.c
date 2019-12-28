#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>

#define MY_ID "netoeuler666\n"
#define MY_ID_LEN 13		/* MY_ID length */

static int foo_len;

static struct kobject *hello_kobj;

static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,
			char *buf)
{
	return sprintf(buf, "%d\n", foo_len);
}

static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	sscanf(buf, "%d\n", &foo_len);
	return count;	
}

static ssize_t id_show(struct kobject *kobj, struct kobj_attribute *attr,
		       char *buf)
{
	char *hello_str = MY_ID;

	return sprintf(buf, "%s\n", hello_str);
}

static ssize_t id_store(struct kobject *kobj, struct kobj_attribute *attr,
			const char *buf, size_t count)
{
	sscanf(buf, "%d\n", &foo_len);
	return count;
}

static ssize_t jiffies_show(struct kobject *kobj, struct kobj_attribute *attr,
			    char *buf)
{
	return sprintf(buf, "%lu\n", jiffies);
}

static ssize_t jiffies_store(struct kobject *kobj, struct kobj_attribute *attr,
			     const char *buf, size_t count)
{
	sscanf(buf, "%d\n", &foo_len);
	return count;
}


static struct kobj_attribute foo_attribute = __ATTR(foo, 0644, foo_show, foo_store);
static struct kobj_attribute id_attribute = __ATTR_RW(id);
static struct kobj_attribute jiffies_attribute = __ATTR(jiffies, 0444, jiffies_show, jiffies_store);

static struct attribute *attrs[] = {
	&foo_attribute.attr,
	&id_attribute.attr,
	&jiffies_attribute.attr,
	NULL,
};

static struct attribute_group hello_group = {
	.attrs = attrs,
};

static int __init hello_init(void)
{
	int retval;

	//Create directory in /sys/kernel
	hello_kobj = kobject_create_and_add("eudyptula", kernel_kobj);
	if (!hello_kobj)
		return -ENOMEM;

	retval = sysfs_create_group(hello_kobj, &hello_group);
	//retval = sysfs_create_file(hello_kobj, &foo_attribute.attr);
	if (retval)
		kobject_put(hello_kobj);

	pr_debug("Hello Task9!\n");
	return retval;
}

static void __exit hello_exit(void)
{
	kobject_put(hello_kobj);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("netoeuler");
MODULE_DESCRIPTION("Task9 module");
