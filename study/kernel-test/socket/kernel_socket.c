/*************************************************************************
    > File Name: kernel_socket.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: Tue 26 Jan 2016 02:40:48 PM CST
 ************************************************************************/
#include<net/tcp.h>
#include<linux/in.h>
#include<linux/inet.h>
#include<linux/module.h>
#include<linux/init.h>

static int err = -1;
static int ok = 0;


static void set_inetaddr(char *ip, unsigned short port, struct sockaddr_in *addr)
{
	memset(addr, 0, sizeof(struct sockaddr_in));
	addr->sin_family = AF_INET;
	addr->sin_addr.s_addr = in_aton(ip);
	addr->sin_port = htons(port);
	return;
}



static int socket_init(void)
{
	struct socket *socket_fd = NULL;
	struct sockaddr_in self_addr;
	struct msghdr tcp_msghdr;

	char *ip="192.168.1.198";
	unsigned short port = 8800;
	int ret = ok;
	char buf[1024] = "hello,i am kernel";
	struct kvec iov;

	set_inetaddr(ip,port,&self_addr);

	if((ret = sock_create_kern(PF_INET, SOCK_STREAM, IPPROTO_TCP, &socket_fd)) < 0)
	{
		printk(KERN_ALERT "fail to create socket_fd \n");
		return err;
	}
	else
	{
		tcp_msghdr.msg_name = (struct sockaddr *) &self_addr;
		tcp_msghdr.msg_namelen = sizeof(struct sockaddr);
		tcp_msghdr.msg_control = NULL;
		tcp_msghdr.msg_controllen = 0;
		tcp_msghdr.msg_flags = MSG_WAITALL;
	}
	
	ret = kernel_connect(socket_fd, (struct sockaddr *) &self_addr, sizeof(struct sockaddr_in),0);
	if(ret < 0)
	{
		printk(KERN_ALERT "fail to connect socket_fd,ret =%d \n",ret);
		return err;
	}

	iov.iov_base = buf;
	iov.iov_len = sizeof(buf);
	ret = kernel_sendmsg(socket_fd, &tcp_msghdr, &iov, 1, iov.iov_len);
	
	if(ret != iov.iov_len)
	{
		printk(KERN_ALERT "send error \n");
		return err;
	
	}

	return ok;
}


static int hello_init(void)
{
	printk(KERN_ALERT "hello,world \n");
	socket_init();
	return ok;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye cruel world \n");
	return;
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
