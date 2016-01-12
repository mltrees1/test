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
	int ret;
	/* exit condition*/
	if((start.x == des.x) && (start.y == des.y) )
	{
		/*reach the destination*/
		return 0;
	}
	if ((start.x >= BOUND_X) || (start.y >= BOUND_Y))
	{
		/*exceed the boundary exit*/
		return 1;
	}

	if(!map_reachable)
	{
		/*the point in map is not avaiable*/
		return 1;
	}

	/*map can reach*/
	for(i = 0; i < 4; i++)
	{
		next.pre_x = start.x;
		next.pre_y = start.y;
		next.x = start.x + step[i][0];
		next.y = start.x + step[i][1];
		book[next.x][next.y] = 1;
		ret = dfs_step(next,des,map);
		book[next.x][next.y] = 0;
	}

	return 1;
}

int dfs(struct PT start,struct PT des,int *map)
{
	dfs_step(start,des,map);
	return 0;
}


