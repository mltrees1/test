/*************************************************************************
    > File Name: main.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: 2016年01月09日 星期六 20时59分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include "common.h"
#include "dfs.h"

int reachable = 0xff;
int row = 0;
int column = 0;

int map[BOUND_X * BOUND_Y];

int step[4][2]={{0,1},
					 {0,-1},
					 {1,0},
					 {-1,0}};
int book[BOUND_X][BOUND_Y];

int parse_map(char *input,int *map)
{
	int i = 0;
	while(input[i] != '\n')
	{
		if(row == 0)
			column++;	//get the colume of map


		if(input[i] == '0')
			map[i] = PLANE;
		else
			map[i] = STONE;
		
		i++;
	}
	return 0;
}

int get_map(char *filename)
{
	FILE *fp;
	char str_line[1024];

	if((fp=fopen(filename,"r")) == NULL)
	{
		printf("error read file\n");
		return -1;
	}
	while(!feof(fp))
	{
		fgets(str_line,1024,fp);	//read one line
		printf("%s\n",str_line);
		parse_map(str_line, &map[row*column]);
		row++;
	}
	fclose(fp);
	return 0;
}

void print_map(int row,int column,int *map)
{
	int i ;
	int j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d  ",map[i*row+j]);
		}
		printf("\n");
	}
	return;
}

int main(int argc, char **argv)
{
	int ret = 0;
	char * filename= NULL;
	
	struct PT start,end;
	if(argc < 2)
	{
		printf("you should input the map name \n");
		return -1;
	}
	filename = (char *)argv[1];
	get_map(filename);
	
	printf("the map array = : \n");
	print_map(row,column,map);

	start.x = 0;
	start.y = 0;
	
	end.x = 1;
	end.y = 2;
	ret = dfs(start,end,map);
	printf("the reachable = %d, ret=%d \n",reachable,ret);

	return 0;

}

