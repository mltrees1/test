/*************************************************************************
    > File Name: kernel_socket.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: Tue 26 Jan 2016 02:40:48 PM CST
 ************************************************************************/
#include<linux/init.h>
#include<linux/module.h>
MODULE_LICENSE("GPL");


static int hello_init(void)
{
	printk(KERN_ALERT "hello,world \n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye cruel world \n");
	return;
}

module_init(hello_init);
module_exit(hello_exit);

