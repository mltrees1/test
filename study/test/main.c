/*************************************************************************
    > File Name: main.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: 2016年01月09日 星期六 20时59分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include "common.h"
#include "bubble_sort.h"
#include "quick_sort.h"
int main()
{
	int min = 10;
	int max = 100;
	int num = 100;
//	int a[] = {100,15,83,65,80,13,69,61,56,75};
	int *a = NULL;
	int *b = NULL;
	int *c = NULL;
	a = gen_random(min, max, num);
	b = (int*)malloc(num*sizeof(int));
	c = (int*)malloc(num*sizeof(int));
	memset(b,0,num);
	memcpy(b,a,num*sizeof(int));
	memcpy(c,a,num*sizeof(int));
	
	/*bubble sort*/
//	bubble_sort(b,num);

	/*quick sort*/
//	quick_sort(c,num);

	free(a);

	free(b);
	free(c);
	a=NULL;
	b=NULL;
	c=NULL;
	return 0;

}

