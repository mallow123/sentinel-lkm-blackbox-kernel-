#include <linux/init.h>       // For __init and __exit macros
#include <linux/module.h>     // For all kernel modules
#include <linux/kernel.h>     // For printk()
#include <linux/sched/signal.h> // For task_struct
#include <linux/sched.h>      // For current process info

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bazerk");
MODULE_DESCRIPTION("Simple process info kernel module");

static int __init procmon_init(void) {
    printk(KERN_INFO "procmon: Module loaded\n");

    // Print info about the current process (the one inserting this module)
    printk(KERN_INFO "procmon: Inserted by process: %s [PID: %d]\n",
           current->comm, current->pid);

    return 0;
}

static void __exit procmon_exit(void) {
    printk(KERN_INFO "procmon: Module unloaded\n");
}

module_init(procmon_init);
module_exit(procmon_exit);
