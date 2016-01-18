/*************************************************************************
    > File Name: dijkstra.h
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月17日 星期日 14时20分05秒
    > Description: 
 ************************************************************************/
#ifndef _DIJKASTRA_H_
#define _DIJKASTRA_H_
#define INF 0xffff
#define OK  0
#define MAX_PATH_LEN 256
int dijkastra(int index, int *map, int num, char **path_out, int *dis_out);
#endif

