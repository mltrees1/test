/*************************************************************************
    > File Name: queue.h
    > Author: zml
    > Mail: maolin.zhang@netbric.com 
    > Created Time: Thu 14 Jan 2016 07:40:04 PM CST
 ************************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef struct
{
	int tail;
	int head;
	int size;
	void **data;
}Queue;

#define QUEUE_SPACE(size,head,tail) ( (head) <= (tail) ? (size-tail + head -1) : (head -tail -1)  )

#define QUEUE_COUNT(size,head,tail) ( (head) <= (tail) ? (tail -head) : (size + tail - head) )

#define is_queue_empty(queue) ( (queue)->tail == (queue)->head  )

#define is_queue_full(queue) ( QUEUE_SPACE((queue)->size,(queue)->head, (queue)->tail) == 0)

#define get_queue_space(queue) ( QUEUE_SPACE( (queue)->size, (queue)->head, (queue)->tail ) )

#define get_queue_count(queue) ( QUEUE_COUNT((queue)->size, (queue)->head, (queue)->tail )


void queue_init(Queue *queue,int queue_size);

void queue_destroy(Queue *queue);


int enqueue(Queue *queue, void* element);


void* dequeue(Queue *queue);

int push(Queue *queue, void* element);

void* pop(Queue *queue);

#endif

