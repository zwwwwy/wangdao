#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
	int				 data;
	struct LinkNode* next;
} LinkNode_t;

typedef struct LinkQueue
{
	LinkNode_t* front;
	LinkNode_t* rear;
} LinkQueue_t;

int InitQueue(LinkQueue_t* queue)
{
	LinkNode_t* node = (LinkNode_t*)malloc(sizeof(LinkNode_t));
	node->next		 = NULL;
	queue->front	 = node;
	queue->rear		 = node;
	return 1;
}

int IsEmpty(LinkQueue_t* queue)
{
	if (queue->front == queue->rear)
		return 1;
	else
		return 0;
}

int EnQueue(LinkQueue_t* queue, int data)
{
	queue->front->data = data;
	LinkNode_t* node   = (LinkNode_t*)malloc(sizeof(LinkNode_t));
	node->next		   = NULL;
	queue->front->next = node;
	queue->front	   = node;
	return 1;
}

int DeQueue(LinkQueue_t* queue, int* data)
{
	if (IsEmpty(queue))
	{
		printf("Queue is empty.\n");
		return 0;
	}
	LinkNode_t* node = queue->rear;
	*data			 = node->data;
	queue->rear		 = node->next;
	free(node);
	return 1;
}

void test()
{
	LinkQueue_t* q = (LinkQueue_t*)malloc(sizeof(LinkQueue_t));
	int			 data;
	InitQueue(q);
	for (int i = 0; i < 5; ++i)
	{
		EnQueue(q, i);
		printf("Enqueue %d.\n", i);
	}

	for (int i = 0; i < 3; ++i)
	{
		DeQueue(q, &data);
		printf("DeQueue %d.\n", data);
	}

	for (int i = 5; i < 10; ++i)
	{
		EnQueue(q, i);
		printf("Enqueue %d.\n", i);
	}

	for (int i = 0; i < 3; ++i)
	{
		DeQueue(q, &data);
		printf("DeQueue %d.\n", data);
	}
	return;
}

int main()
{
	test();
	return 0;
}
