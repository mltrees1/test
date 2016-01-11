/*************************************************************************
    > File Name: dfs.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月10日 星期日 19时50分17秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<common.h>


int a[9];
int input[9];
int book[9];
int count = 0;

char check_result()
{
	int r1=0;
	int r2=0;
	r1 = (100*a[0]+10*a[1]+a[2]) + (100*a[3] + 10*a[4] + a[5]);
	r2 = (100*a[6]+10*a[7]+a[8]);
	if(r1 == r2)
		return 1;
	else
		return 0;
}

void init_input()
{
	int i;
	for(i = 0; i < 9;i++)
	{
		input[i] = i+1;
	}
	return;	
}

int dfs(int step)
{
	int i;
	if(step == 9)
	{
		if(check_result())	
		{
			printf("%d%d%d+%d%d%d=%d%d%d \n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
			count++;
			return 0;
		}
	}
	for(i = 0; i < 9; i++)
	{
		if(book[i] == 0)
		{
			a[step] = input[i];
			book[i] = 1;
			dfs(step+1);
			book[i] = 0;
		}
	}
	return 0;
}


int main()
{
	int first_step = 0;
	init_input();
	dfs(first_step);
	printf("count = %d \n",count);
	return 0;
}
