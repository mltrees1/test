/*************************************************************************
    > File Name: main.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月17日 星期日 21时18分12秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NOT_FOUND 0xff


int is_number(char c)
{
	int ret = 0;
	if((c >='0' ) &&( c <= '9'))
		ret = 1;

	return ret;
}

int continumax(char *outputstr,char *inputstr)
{
	int max_num_len = 0;
	int index = NOT_FOUND;
	int i = 0;
	int tmp_index = NOT_FOUND;
	int tmp_len = 0;
	int continue_flag = 0;

	i = 0;
	while(inputstr[i] != '\0')
	{
		if(is_number(inputstr[i]))
		{
			if(continue_flag == 0)
			{
				tmp_index = i;
			}
			continue_flag = 1;
			tmp_len ++;
		}
		else
		{
			continue_flag = 0;
			tmp_len = 0;
		}

		if(tmp_len > max_num_len)
		{
			max_num_len = tmp_len;
			index = tmp_index;
		}
		i++;
	}
	
	memcpy(outputstr,&inputstr[index],max_num_len);

	return max_num_len;
}

int main()
{
	int ret;
	char *input="abcd123451234512345ed125ss123456789";
	char *output = NULL;
	output = (char*)malloc(1024);
	memset(output,0,(size_t)1024);

	ret = continumax(output,input);
	printf("ret = %d \n",ret);
	printf("outputstr=%s \n",output);
	return 0;
}



