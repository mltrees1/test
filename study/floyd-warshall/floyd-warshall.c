/*************************************************************************
    > File Name: floyd-warshall.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月17日 星期日 09时59分16秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "common.h"
#include<string.h>

int malloc_path(char **path,int length, int vertex_num)
{
	int i;
	for(i = 0; i < vertex_num*vertex_num; i++)
	{
		path[i] = (char*)malloc((size_t)length*sizeof(char));
		memset(path[i],0,(size_t)length*sizeof(char));
	}
	return OK;
}

int init_path(char **path,int length,int vertex_num)
{
	int i,j;
	for(i = 0; i < vertex_num; i++)
		for(j = 0; j < vertex_num; j++)
		{
			snprintf(path[i*vertex_num+j],length,"%d->%d",i,j);
		}

	return OK;
}

int print_path(char **path, int vertex_num)
{
	int i,j;
	for(i = 0; i < vertex_num; i ++)
	{
		for(j = 0; j < vertex_num; j++)
		{
			printf("%d to %d, the shortest map is :%s \n",i,j,path[i*vertex_num+j]);
		}
	}
	return OK;
}

int destroy_path(char **path,int vertex_num)
{
	int i;
	for(i = 0; i < vertex_num*vertex_num; i++)
	{
		free(path[i]);
		path[i]=NULL;
	}
	return OK;	
}

int init_dis_from_map(int * dis, int *map,int vertex_num)
{
	int i;
	for(i = 0; i < vertex_num*vertex_num; i++)
	{
		dis[i] = map[i];
	}
	return OK;
}

int print_distance(int *distance, int vertex_num)
{
	int i,j;
	for(i = 0; i < vertex_num; i++)
	{
		for(j = 0; j < vertex_num; j++)
		{
			printf("%d  ",distance[i*vertex_num+j]);
		}
		printf("\n");
	}

	return OK;
}

int floyd_warshall(int * map, int vertex_num)
{
	int i,j,k;
	int max_path_len=128;
	int dis[vertex_num*vertex_num];
	char *path[vertex_num*vertex_num];
	
	init_dis_from_map(dis,map,vertex_num);
	malloc_path(path,max_path_len,vertex_num);
	init_path(path,max_path_len,vertex_num);

	for(k=0; k < vertex_num; k++)
	{	
		for(i = 0; i < vertex_num; i++)
		{
			for(j = 0; j < vertex_num; j++)
			{
				if(dis[i*vertex_num+j] > dis[i*vertex_num+k] + dis[k*vertex_num +j] )
				{
					dis[i*vertex_num+j] = dis[i*vertex_num+k] + dis[k*vertex_num +j];
					snprintf(path[i*vertex_num +j],max_path_len,"%s,%s",path[i*vertex_num+k],path[k*vertex_num + j]);
				}
			}
		}
	}
	
	printf("the floyd-warrshall result: \n");
	print_distance(dis,vertex_num);
	printf("the path result is \n");
	print_path(path,vertex_num);

	destroy_path(path,vertex_num);
	return OK;
}
