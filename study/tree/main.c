/*************************************************************************
    > File Name: main.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月24日 星期日 10时32分52秒
    > Description: 
 ************************************************************************/
#include<stdio.h>

#include "tree.h"

int main()
{
	int n = 20;
	int depth = 0;
	depth = get_tree_depth(n);
	printf("n=%d, depth=%d \n",n,depth);
	Tree *t;
	t = create_tree(n);
	//print_tree(t,1);
	printf("the mid traverse \n");
	print_tree_mid(t,1);
	//printf("the back traverse \n");
	
	//print_tree_after(t,1);
	printf("the mid no recurse traverse \n");
	print_tree_mid_no_recurse(t);

	return 0;
}
