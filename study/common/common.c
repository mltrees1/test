/*************************************************************************
    > File Name: common.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: 2016年01月09日 星期六 21时31分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include "common.h"
int * gen_random(int range_min, int range_max,int num)
{
	int *array = NULL;
	int i;
	int deno;
	if(range_min >=range_max)
	{
		printf("the input min must lesson than max");
		return NULL;
	}
	if(num <=0)
	{
		printf("the input num must more than 0");
		return NULL;
	}
	deno = range_max - range_min;
	srand(time(0));
	array = (int*)malloc(num*sizeof(int));
	for(i = 0; i < num; i++)	
	{
		array[i] = range_min + rand()%deno;
	}
	
	return array;

}

void print_array_int(int *input,int num)
{
	int i;
	if(num < 0)
	{
		printf("error input in %s",__FUNCTION__);
		return;
	}
	for(i = 0; i < num; i++)
	{
		printf("%d  ",input[i]);
		if((i != 0)&&(i % 20 == 0))
			printf("\n");
	}
	printf("\n");
}

