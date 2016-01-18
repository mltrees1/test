/*************************************************************************
    > File Name: dijkstra.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月17日 星期日 14时19分39秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dijkstra.h"

int	update_dis_from_map(int index,int num,int *map,int *out)
{
	memcpy(out,&map[index*num],(size_t)num*sizeof(int));
	return OK;
}

int init_path(char **path,int num)
{
	int i,j;
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			path[i*num+j] = (char*)malloc((size_t)MAX_PATH_LEN*sizeof(char));
			memset(path[i*num+j],0,(size_t)MAX_PATH_LEN*sizeof(char));
			snprintf(path[i*num+j],MAX_PATH_LEN,"%d->%d",i,j);
		}
	}
	return OK;
}

static int destroy_path(char **path,int num)
{
	int i,j;
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			free(path[i*num + j]);
			path[i*num +j] = NULL;
		}
	}

	return OK;
}

static int update_path(char *path,char *branch_path1,char *branch_path2)
{
	snprintf(path,MAX_PATH_LEN,"%s,%s",branch_path1,branch_path2);
	return OK;
}

static int cp_path(char **des,char **src, int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		strcpy(des[i],src[i]);
	}
	return OK;
}

int dijkastra(int index, int *map, int num, char **path_out, int *dis_out)
{
	int i,j;
	int v;
	int book[num];
	int *dis = dis_out;
	int min = 0;
	char *path[num*num];

	memset(book,0,(size_t)num*sizeof(int));
	memset(dis,0,(size_t)num*sizeof(int));
	update_dis_from_map(index,num,map,dis);
	init_path(path, num);
	book[index] = 1;
	for(i = 0; i < num; i++)
	{
		min = INF;
		for(j = 0; j < num; j++)
		{
			if((book[j] == 0) && (min > dis[j]))
			{
				min = dis[j];
				v = j;			
			}
		}
		book[v] = 1;
		for(j = 0; j < num; j++)
		{
			if(book[j] == 0)
			{
			
				if(dis[j] > dis[v] + map[v*num + j])
				{
					dis[j] = dis[v] +map[v*num + j];
					update_path(path[index*num+j],path[index*num +v],path[v*num+j]);	
				}
			}	
		}
	}

	cp_path(path_out,&path[index*num],num);
	destroy_path(path,num);
	return OK;
}

