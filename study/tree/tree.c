/*************************************************************************
    > File Name: tree.c
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月24日 星期日 10时44分00秒
    > Description: 
 ************************************************************************/
#include<stdio.h>
#include<math.h>
#include "tree.h"
#include<stdlib.h>
#include<string.h>
#include "queue.h"
const int max_depth=10;
const int err = -1;
const int ok = 0;


int create_tree_node(int *value,Tree *t,int current_depth,int depth,int *current_node_num, int node_num);
int get_tree_depth(int n)
{
	if (n > pow(2,max_depth)-1)
	{
		printf("the input number should less than %d \n",(int)pow(2,max_depth));
		return err;
	}
	if(n <=0 )
	{
		printf("the input should not equal or less than 0 \n");
		return err;
	}

	int i = 0;
	while(n >= pow(2,i))
	{
		i++;
		if(i >=max_depth)
		{
			break;
		}
	}
	return i;
}

Tree* create_tree(int node_num)
{
	int depth = 0;
	int value = 0;
	int current_depth = 0;
	int current_node_num = 0;
	int ret;

	depth = get_tree_depth(node_num);
	if(depth < 0)
	{
		printf("error input node num \n");
		return NULL;
	}
	
	Tree *t =(Tree *)malloc(sizeof(Tree));
	if(NULL == t)
	{
		printf("malloc failed \n");
		return NULL;
	}
	memset(t,0,sizeof(Tree));
	t->node.value = value;
	value++;
	current_depth++;
	current_node_num++;
	ret = create_tree_node(&value,t,current_depth,depth,&current_node_num,node_num);

	if(ret == ok)
		return t;	
	else
		return NULL;
}

int create_tree_node(int *value,Tree *t,int current_depth,int depth,int* current_node_num, int node_num)
{
	int ret = ok;
	if(!t)
	{
		printf("the input tree pointer should not be NULL \n");
		return err;
	}
	if(current_depth >= depth)
	{
		return ok;
	}

	if(!t->pleft)
	{
		t->pleft=(Tree *)malloc(sizeof(Tree));
		if(!t->pleft)
		{
			printf("malloc failed \n");
			return err;
		}
		memset(t->pleft,0,sizeof(Tree));
		t->pleft->node.value = *value;
		*current_node_num=*current_node_num+1;
		if(*current_node_num < node_num)
		{
			*value = *value+1;
			ret = create_tree_node(value,t->pleft,current_depth+1,depth,current_node_num,node_num);
		}
	}
	
	if((!t->pright) && (ret != err) &&(*current_node_num < node_num))
	{
		t->pright=(Tree *)malloc(sizeof(Tree));
		if(!t->pright)
		{
			printf("malloc failed \n");
			return err;
		}
		memset(t->pright,0,sizeof(Tree));
		t->pright->node.value = *value;
		*current_node_num=*current_node_num+1;
		if(*current_node_num < node_num)
		{
			*value = *value+1;
			ret = create_tree_node(value,t->pright,current_depth+1,depth,current_node_num,node_num);
		}
	}

	return ret;
}

int print_tree(Tree *t,int blk)
{
	int i;
	for(i = 0;i < blk;i++)
	{
		printf("    ");
	}
	if(t != NULL)
	{
		printf("|-<%d> \n",t->node.value);
		print_tree(t->pleft,blk+1);
		print_tree(t->pright,blk+1);
	}
	else
	{
		printf("NULL \n");
	}

	return ok;
}

int print_tree_no_recursion(Tree *t)
{
	Queue q;
	int q_size = 1024;
	Tree *p_tmp = NULL;

	queue_init(&q,q_size);

	push(&q,(void *)t);

	p_tmp=dequeue(&q);
	
	
	while((p_tmp != NULL) || (!is_queue_empty(&q))  )
	{
		while(p_tmp != NULL)
		{
			printf("|-<%d>\n",p_tmp->node.value);
			push(&q,(void *)p_tmp);
			p_tmp=p_tmp->pleft;
		}

		p_tmp = pop(&q);
		if(p_tmp != NULL)
		{
			p_tmp = p_tmp->pright;
		}
	}

	queue_destroy(&q);
	
	return ok;

}



int print_tree_mid(Tree *t,int blk)
{
	int i;
	if(t != NULL)
	{
		print_tree_mid(t->pleft,blk+1);
		for(i = 0;i < blk;i++)
		{
			printf("    ");
		}
		printf("|-<%d> \n",t->node.value);
		print_tree_mid(t->pright,blk+1);
	}
	else
	{
		printf("NULL \n");
	}

	return ok;
}

int print_tree_after(Tree *t,int blk)
{
	int i;
	if(t != NULL)
	{
		print_tree_after(t->pleft,blk+1);
		print_tree_after(t->pright,blk+1);

		for(i = 0;i < blk;i++)
		{
			printf("    ");
		}
		printf("|-<%d> \n",t->node.value);
	}
	else
	{
		printf("NULL \n");
	}

	return ok;
}

int print_tree_mid_no_recurse(Tree *t)
{
	Queue q;
	int q_size=1024;
	Tree *p_tmp = NULL;

	queue_init(&q,q_size);

	p_tmp = t;

	while((p_tmp != NULL) ||(!is_queue_empty(&q)))
	{
		while(p_tmp != NULL)
		{
			push(&q,p_tmp);
			p_tmp = p_tmp->pleft;
		}

		if(!is_queue_empty(&q))
		{
			p_tmp = pop(&q);
			printf("|-<%d>\n",p_tmp->node.value);
			p_tmp = p_tmp->pright;
		}
	}

	queue_destroy(&q);
	return ok;
}



