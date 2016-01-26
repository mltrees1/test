MODULE_NAME := test_socket
$(MODULE_NAME)-objs:= kernel_socket.o
EXTRA_CFLAGS=-I$(PWD)/../../include                                                                           
CURRENT = $(shell uname -r)
KDIR = /lib/modules/$(CURRENT)/build/

obj-m :=kernel_socket.o

SRCS = kernel_socket.c

OBJS = $(SRCS:.c=.o)
ccflags-y += -g -O0

default:
	$(MAKE) -C $(KDIR) M=`pwd` modules
clean:
	$(MAKE) -C $(KDIR) M=`pwd` clean
	$(RM) Module.markers modules.order *.o

