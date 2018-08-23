/* 
  file: hello.c -- for test the firsr moude  
  Copyright (c) 2018.8 gaopan <gaopan0412@outlook.com>
  Date : 2018-8-23
*/
#include <linux/module.h>
#include <linux/init.h>

static int __init hello_init(void)
{
	printk("[hello] this is hello module\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk("[hello]bye bye hello moudule\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");

