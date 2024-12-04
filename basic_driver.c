#include <linux/module.h>
#include <linux/kernel.h>

// Module initiation function
static int __init basic_driver_init(void) {
    printk(KERN_INFO "Basic Driver Loaded\n");
    return 0; // Return 0 indicates successful loading
}

// Module cleanup function
static void __exit basic_driver_exit(void) {
    printk(KERN_INFO "Basic Driver Unloaded\n");
}

// Register module initiation and cleanup function
module_init(basic_driver_init);
module_exit(basic_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Meghana");
MODULE_DESCRIPTION("A Basic Linux Device Driver");

