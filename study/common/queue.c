/*************************************************************************
    > File Name: queue.c
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: Thu 14 Jan 2016 08:26:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include "queue.h"

void queue_init(Queue *queue,int queue_size)
{
	queue->head = queue->tail = 0;
	queue->size = queue_size;
	queue->data = (void**)malloc((size_t)queue->size*sizeof(void*));
	return;
}

void queue_destroy(Queue *queue)
{
	free(queue->data);
}

int enqueue(Queue *queue, void* element)
{
	if(is_queue_full(queue))
		return -EAGAIN;

	queue->data[queue->tail] = element;
	queue->tail++;
	if(queue->tail == queue->size)
		queue->tail = 0;

	return 0;
}

void* dequeue(Queue *queue)
{
	if(is_queue_empty(queue))
		return NULL;

	void *r = queue->data[queue->head];
	queue->head++;
	
	if(queue->head == queue->size)
		queue->head = 0;

	return r;
}


