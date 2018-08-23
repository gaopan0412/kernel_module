/*
 	File: __module_address.c
	Date: 2018-08-23
	AUT : gaopan
	Copyright (c) 2018 gaopan <gaopan0412@outlook.com> 
*/

#include <linux/module.h>
#include <linux/init.h>

int a_module(void)
{
	return 0;
}

static int __init __module_address_init(void)
{
	struct module *ret;
	unsigned long addr = (unsigned long)a_module;
	
	preempt_disable();
	ret = __module_address(addr);
	preempt_enable();

	if (ret != NULL) {
		printk("ret->name: %s\n", ret -> name);
		printk("ret->state: %d\n", ret -> state);
		printk("ret->core_size:%d\n", ret -> core_size);
		printk("refs of %s is %d\n", ret->name, module_refcount(ret));	
	} 
	else {
		printk("__module_address return NULL !\n");
	}

	return 0;
}

static void __exit __module_address_exit(void)
{
	printk("module exit ok!\n");
}

module_init(__module_address_init);
module_exit(__module_address_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("gaopan <gaopan0412@outlook.com>");
