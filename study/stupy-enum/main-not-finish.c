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

char check_result()
{
	int r1=0;
	int r2=0;
	r1 = (a[0]+10*a[1]+100*a[2]) + (a[3] + 10*a[4] + 100*a[5]);
	r2 = (a[6]+10*a[7]+100*a[8]);

	if(r1 == r2)
		return 1;
	else
		return 0;
}

void init_input()
{
	int i;
	for(i = 0; i < 10;i++)
	{
		input[i] = i+1;
	}
	return;	
}

int stupy()
{
	int cycle[9];
	for(cycle[0]= 0; cycle[0]< 10; cycle[0]++)
	{
		if(book[cycle[0]] == 0)
		{
			a[cycle[0]] = input[cycle[0]];
			book[cycle[0]] = 1;
		}

	}

	return 0;
}


int main()
{
	int first_step = 1;
	init_input();
	dfs(first_step);
	return 0;
}
