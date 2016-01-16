/*************************************************************************
    > File Name: bfs.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月12日 星期二 08时01分00秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "bfs.h"
#include "queue.h"
#include<string.h>

extern int row;
extern int column;
extern int step[4][2];
extern int reachable;
struct PT* pbook[BOUND_X][BOUND_Y];
extern Queue *p_path_queue;
extern Queue *p_book_queue;

void print_path(struct PT *pt)
{
	struct PT *tmp_pt = NULL;
	tmp_pt=pt;
	while(tmp_pt)
	{
		printf("(%d,%d)  ",tmp_pt->x,tmp_pt->y);
		tmp_pt=tmp_pt->pre_pt;
	}
	printf("\n");
}

int map_reachable(struct PT pt,int *map)
{
	if ((pt.x >= BOUND_X) || (pt.y >= BOUND_Y) || 
			(pt.x < 0) || (pt.y < 0))
	{
		/*exceed the boundary,can not reach*/
		return 0;
	}
	if(pbook[pt.x][pt.y] != NULL)
	{
		/*the point is reached before*/
		return 0;
	}

	if(map[pt.x*column + pt.y] != PLANE)
	{
		return 0;/*can not reach*/
	}
	else
	{
		return 1;/*can reach */
	}
}

void free_step(struct PT pt)
{
	int i,j;
	for(i = 0; i < BOUND_X; i++)
	{
		for(j = 0; j < BOUND_Y; j++)
		{
			if((pt.x == i) && (pt.y == j))
				continue;

			if(pbook[i][j])
				free(pbook[i][j]);
		}
	}
}

int reach_des(struct PT* pt,struct PT*des)
{
	int ret = 0;
	if((pt->x == des->x) && (pt->y == des->y))
		ret = 1;

	return ret;
}

int bfs(struct PT start,struct PT des,int *map)
{
	int ret = 0;
	int i = 0;
	struct PT* pnext = NULL;
	struct PT* pnow  = NULL;
	struct PT tmp;
	/*enqueue the bfs queue*/
	enqueue(p_book_queue,&start);
	pbook[start.x][start.y] = &start;
	pnow=dequeue(p_book_queue);
	while(pnow)
	{
		if(reach_des(pnow,&des))
		{
			print_path(pnow);
			reachable = 1;
			break;
		}

		for(i = 0; i < 4; i++)
		{
			tmp.x = pnow->x + step[i][0];
			tmp.y = pnow->y + step[i][1];
			if(map_reachable(tmp,map))
			{
				pnext = (struct PT*)malloc((size_t)sizeof(struct PT));
				memcpy(pnext,&tmp,sizeof(struct PT));
				pnext->pre_pt = pnow;
				enqueue(p_book_queue,pnext);
				pbook[pnext->x][pnext->y] = pnext;
			}
		}
		pnow=dequeue(p_book_queue);
	}
	free_step(start);

	return ret;
}


