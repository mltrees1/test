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
#include "queue.h"
#include "floyd-warshall.h"

void print_map(int row,int column,int *map)
{
	int i ;
	int j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d    ",map[i*row+j]);
		}
		printf("\n");
	}
	return;
}

int init_map(int *map, int vertex_num)
{
	int i,j;
	for(i =0; i < vertex_num; i++)
	{
		for(j = 0; j < vertex_num; j++)
		{
			map[i*vertex_num+j] = INFI_DIS;
		}
	}
	map[0*4+0] = 0;
	map[0*4+1] = 2;
	map[0*4+2] = 6;
	map[0*4+3] = 4;
	map[1*4+1] = 0;
	map[1*4+2] = 3;
	map[2*4+0] = 7;
	map[2*4+2] = 0;
	map[2*4+3] = 1;
	map[3*4+0] = 5;
	map[3*4+2] = 12;
	map[3*4+3] = 0;
	return OK;
}

int main()
{
	int vertex_num = 4;
	int map[vertex_num*vertex_num];
	int ret;

	init_map(map,vertex_num);

	printf("the map array = : \n");
	print_map(vertex_num,vertex_num,map);
	printf("\n");

	ret = floyd_warshall(map,vertex_num);

	


	return ret;

}

