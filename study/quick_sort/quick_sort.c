/*************************************************************************
    > File Name: quick_sort.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月10日 星期日 13时50分21秒
    > Comment: 
 ************************************************************************/
#include<stdio.h>
#include "common.h"
#include "bubble_sort.h"
int quick_sort(int *input,int num)
{
	int key;
	int i,j;

	if(num <=0)
	{
		printf("error input in function %s \n",__FUNCTION__);
		return -1;
	}

	if(num <= 3)
	{
		bubble_sort(input,num);
		return 0;
	}
	
	/*quick sort algrithm*/
	key = input[0];
	i = 1;
	j = num - 1;
	while(i <= j)
	{
		while((input[j] >= key) &&( i <= j )  )
		{
			j--;
		}
		
		while((input[i] <= key) && (i <= j))
		{
			i++;
		}

		if (i < j)
			swap(input[i],input[j]);
	}
	swap(input[0],input[j]);

	quick_sort(&input[0],j);
	quick_sort(&input[j+1],num - j -1);
	return 0;
}
