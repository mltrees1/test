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
#include<string.h>

void queue_init(Queue *queue,int queue_size)
{
	queue->head = queue->tail = 0;
	queue->size = queue_size;
	queue->data = (void**)malloc((size_t)queue->size*sizeof(void*));
	memset((void*)queue->data,(int)0,(size_t)queue_size*sizeof(void*));
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

int push(Queue *queue, void* element)
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

void* pop(Queue *queue)
{
	int tail = 0;
	if(is_queue_empty(queue))
		return NULL;
	
	tail = queue->tail -1;
	if(tail < 0)
		tail = queue->size -1;

	void *r = queue->data[tail];
	queue->tail = tail;
	
	return r;
}
