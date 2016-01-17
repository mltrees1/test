/*************************************************************************
    > File Name: common.h
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: 2016年01月09日 星期六 21时43分01秒
 ************************************************************************/

#ifndef COMMON_H
#define COMMON_H

#define swap(a,b) {a=a+b;b=a-b;a=a-b;}
int * gen_random(int range_min, int range_max,int num);
void print_array_int(int *input,int num);
#define OK 0

#endif
