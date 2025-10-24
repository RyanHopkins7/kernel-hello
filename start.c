// start.c - Illustration of multi filed modules
#include <linux/init.h> // __init / __exit macros
#include <linux/module.h> // We're building a Linux kernel module
#include <linux/printk.h> // pr_info

static int __init hello_init(void)
{
    pr_info("Hello, world!\n");
    return 0;
}

module_init(hello_init);

MODULE_LICENSE("GPL");
