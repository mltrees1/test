/*************************************************************************
    > File Name: dfs.h
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月12日 星期二 08时06分56秒
    > Description: 
 ************************************************************************/
#ifndef _DFS_H_
#define _DFS_H_


#define UN_REACH 0xff
#define BOUND_X 10
#define BOUND_Y 10
#define STONE 1	/*stone represent can pass*/
#define PLANE 0	/* plane represent can not pass*/

struct PT {
	int x;
	int y;
	struct PT *pre_pt;
};

int bfs(struct PT start,struct PT des,int *map);
#endif

