#define MAXLEN 5
#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
	int data[MAXLEN];
	int front;
	int rear;
	int maxlen;
} queue_t;

int InitQueue(queue_t* queue)
{
	queue->front  = 0;
	queue->rear	  = 0;
	queue->maxlen = MAXLEN;
	return 1;
}

int QueueEmpty(queue_t* queue)
{
	if (queue->front == queue->rear)
		return 1;
	else
		return 0;
}

int EnQueue(queue_t* queue, int data)
{
	if ((queue->front + 1) % queue->maxlen == queue->rear)
	{
		printf("Queue full.\n");
		return 0;
	}
	queue->data[queue->front] = data;

	queue->front = (queue->front + 1) % queue->maxlen;
	return 1;
}

int DeQueue(queue_t* queue, int* data)
{
	if (QueueEmpty(queue))
	{
		printf("Queue is empty.\n");
		return 0;
	}
	*data		= queue->rear;
	queue->rear = (queue->rear + 1) % queue->maxlen;
	return 1;
}

int GetHead(queue_t* queue, int* data)
{
	if (QueueEmpty(queue))
		return 0;

	*data = queue->data[(queue->front - 1) % queue->maxlen];
	return 1;
}

void test()
{
	queue_t* q = (queue_t*)malloc(sizeof(queue_t));
	InitQueue(q);
	int data;
	for (int i = 0; i < 6; ++i)
	{
		if (EnQueue(q, i))
			printf("Enqueue %d.\n", i);
	}

	for (int i = 0; i < 2; ++i)
	{
		if (DeQueue(q, &data))
			printf("Dequeue %d.\n", data);
	}

	for (int i = 4; i < 6; ++i)
	{
		if (EnQueue(q, i))
			printf("Enqueue %d.\n", i);
	}

	GetHead(q, &data);
	printf("data=%d.\n", data);
	return;
}

int main()
{
	test();
	return 0;
}
