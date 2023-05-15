#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

#define BUILD_TIME   __DATE__ " " __TIME__


MODULE_LICENSE("Dual BSD/GPL");

static int test_init(void){
    printk("hello\n");
    return 0;
}

static void test_exit(void){
    printk("module exit\n");
}

module_init(test_init);
module_exit(test_exit);