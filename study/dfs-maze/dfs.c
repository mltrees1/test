/*************************************************************************
    > File Name: dfs.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月12日 星期二 08时01分00秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include "dfs.h"
extern int row;
extern int column;
extern int step[4][2];
extern int book[BOUND_X][BOUND_Y];
extern int reachable;

int map_reachable(struct PT pt,int *map)
{
	if(map[pt.x*column + pt.y] != PLANE)
	{
		return 0;/*can not reach*/
	}
	else
	{
		return 1;/*can reach */
	}
}


int dfs_step(struct PT start,struct PT des,int *map)
{
	int i;
	struct PT next;
	int ret = 0;
	/* exit condition*/
	if ((start.x >= BOUND_X) || (start.y >= BOUND_Y) || 
			(start.x < 0) || (start.y < 0))
	{
		/*exceed the boundary exit*/
		return 1;
	}


	if(!map_reachable(start,map))
	{
		/*the point in map is not avaiable*/
		return 1;
	}
	if((start.x == des.x) && (start.y == des.y) )
	{
		/*reach the destination*/
		reachable = 1;
		return 0;
	}

	/*map can reach*/
	next.x = start.x;
	next.y = start.y;
	for(i = 0; i < 4; i++)
	{
		next.pre_x = start.x;
		next.pre_y = start.y;
		next.x = start.x + step[i][0];
		next.y = start.y + step[i][1];
		if(book[next.x][next.y] == 0)
		{
			book[next.x][next.y] = 1;
			ret = dfs_step(next,des,map);
			book[next.x][next.y] = 0;
			if(ret == 0)
			{
				break;				
			}
		}
	}

	return ret;
}

int dfs(struct PT start,struct PT des,int *map)
{
	int ret;
	ret = dfs_step(start,des,map);
	return ret;
}


