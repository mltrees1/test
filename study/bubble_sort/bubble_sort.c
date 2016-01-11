/*************************************************************************
    > File Name: bubble_sort.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: 2016年01月10日 星期日 10时27分41秒
	> comment : bubble sort implementation
 ************************************************************************/

#include<stdio.h>
#include<common.h>
#include<bubble_sort.h>
int bubble_sort(int *input,int num)
{
	int i ,j;
	if(num < 0)
	{
		printf("error input of num in function %s",__FUNCTION__);
	}
	for(i=num-1; i > 0; i--)
	{
		for(j = 0; j <= i-1; j++)
		{
			if(input[j] > input[j+1])
			{
				swap(input[j],input[j+1]);
			}
		}
	}
	return 0;
}
