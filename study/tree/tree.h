/*************************************************************************
    > File Name: tree.h
    > Author: zml
    > Mail: mltrees@163.com 
    > Created Time: 2016年01月24日 星期日 10时31分22秒
    > Description: 
 ************************************************************************/
#ifndef _TREE_H_
#define _TREE_H_
typedef struct Node
{
	int value;
}Node;

typedef struct Tree
{
	Node node;
	struct Tree *pleft;
	struct Tree *pright;
}Tree;


int get_tree_depth(int n);
Tree* create_tree(int node_num);
int print_tree(Tree *t,int blk);
int print_tree_no_recursion(Tree *t);
int print_tree_mid(Tree *t,int blk);
int print_tree_after(Tree *t,int blk);
int print_tree_mid_no_recurse(Tree *t);
#endif

