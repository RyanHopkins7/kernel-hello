/*   
 * hello-2.c - Illustrating the __init, __initdata and __exit macros.  
 */

#include <linux/init.h> /* Needed for the macros */  
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */  

// Variables in __initdata are only needed during initialization of the Linux kernel module
static int hello2_data __initdata = 2;  


static int __init hello_2_init(void)
{
    pr_info("Hello, world %d\n", hello2_data);

    return 0;  
}

static void __exit hello_2_exit(void)
{
    pr_info("Goodbye, world 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);

MODULE_LICENSE("GPL");