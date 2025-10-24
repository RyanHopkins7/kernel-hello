// stop.c - Illustration of multi filed modules
#include <linux/init.h> // __init / __exit macros
#include <linux/module.h> // We're building a Linux kernel module
#include <linux/printk.h> // pr_info

static void __exit hello_exit(void)
{
    pr_info("Goodbye, world!\n");
}

module_exit(hello_exit);

MODULE_LICENSE("GPL");
