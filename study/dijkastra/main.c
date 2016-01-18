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
#include "dijkstra.h"

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
			map[i*vertex_num+j] = INF;
		}
	}
	map[0*vertex_num+0] = 0;
	map[0*vertex_num+1] = 1;
	map[0*vertex_num+2] = 12;
	map[1*vertex_num+1] = 0;
	map[1*vertex_num+2] = 9;
	map[1*vertex_num+3] = 3;
	map[2*vertex_num+2] = 0;
	map[2*vertex_num+4] = 5;
	map[3*vertex_num+2] = 4;
	map[3*vertex_num+3] = 0;
	map[3*vertex_num+4] = 13;
	map[3*vertex_num+5] = 15;
	map[4*vertex_num+4] = 0;
	map[4*vertex_num+5] = 4;
	map[5*vertex_num+5] = 0;
	return OK;
}

static int init_path(char **path, int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		path[i] = (char*)malloc((size_t)MAX_PATH_LEN*sizeof(char));
		memset(path[i],0,(size_t)MAX_PATH_LEN*sizeof(char));
	}

	return OK;
}

static int destroy_path(char **path,int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		free(path[i]);
		path[i] = NULL;
	}

	return OK;
}

static int print_dis(int *input,int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("%d   ", input[i]);
	}
	printf("\n");

	return OK;
}

static int print_path(char **path, int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("index=%d,path=%s \n",i,path[i]);
	}
	return OK;
}



int main()
{
	int vertex_num =6;
	int index = 0;
	int map[vertex_num*vertex_num];
	int ret;
	int dis[vertex_num];
	char *path[vertex_num];

	init_path(path,vertex_num);

	init_map(map,vertex_num);

	printf("the map array = : \n");
	print_map(vertex_num,vertex_num,map);
	printf("\n");

	ret = dijkastra(index,map,vertex_num,path,dis);
	print_dis(dis,vertex_num);
	print_path(path,vertex_num);
	
	destroy_path(path,vertex_num);


	return ret;

}

