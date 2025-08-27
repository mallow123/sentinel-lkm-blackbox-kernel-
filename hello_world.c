#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bazerk");
MODULE_DESCRIPTION("Hello World Kernel Module");

static int __init hello_init(void) {
    pr_info("Hello, Kernel World!\n");
    return 0;
}

static void __exit hello_exit(void) {
    pr_info("Goodbye, Kernel World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
