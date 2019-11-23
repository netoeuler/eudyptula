#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/export.h>
#include <linux/hid.h>

static int pen_probe(struct usb_interface *interface,
		const struct usb_device_id *id){
	pr_alert("[*eudyptula] USB plugged in\n");
	return 0;
}

static void pen_disconnect(struct usb_interface *interface){
	pr_alert("[*eudyptula] USB disconnected.\n");
}
static struct usb_device_id pen_table[] = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{}
};

MODULE_DEVICE_TABLE(usb, pen_table);

static struct usb_driver pen_driver = {
	.name = "Eudyptula-USB Generic-Driver",
	.id_table = pen_table,
	.probe = pen_probe,
	.disconnect = pen_disconnect,
};

static int __init hello_init(void){
	//printk(KERN_INFO "Hell yeah!\n");
	int ret = -1;
	pr_alert("Registering...\n");
	ret = usb_register(&pen_driver);
	pr_alert("Hell yeah!\n");
	return ret;
}

static void __exit hello_cleanup(void){
	//printk(KERN_INFO "Cleaning out my closet...\n");
	pr_alert("Cleaning out my closet...\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("netoeuler");
MODULE_DESCRIPTION("Editted task5 module");

