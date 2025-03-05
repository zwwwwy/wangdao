#include <stdio.h>
#include <stdlib.h>

/*
 * 前插法，王道用的后插
 */
typedef struct LNode
{
	int			  data;
	struct LNode* next;
} LNode_t;

int InitList(LNode_t* list)
{
	list->next = NULL;
	list->data = 666;
	return 1;
}

int IsEmpty(LNode_t* list)
{
	if (list->next == NULL)
		return 1;
	else
		return 0;
}

int AppendNode(LNode_t* list, int data)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	LNode_t* new_node = (LNode_t*)malloc(sizeof(LNode_t));
	new_node->data	  = data;
	new_node->next	  = NULL;
	list->next		  = new_node;
	return 1;
}

int PrintList(LNode_t* list)
{
	if (IsEmpty(list))
		return 0;
	list = list->next;
	do
	{
		printf("%d ", list->data);
		list = list->next;
	} while (list != NULL);
	printf("\n");
	return 1;
}

int InsertNode(LNode_t* list, int data, int idx)
{
	if (IsEmpty(list))
		return 0;

	for (int i = 0; i < idx; ++i)
	{
		list = list->next;
		if (list->next == NULL && i != idx - 1)
			return 0;
	}
	LNode_t* new_node = (LNode_t*)malloc(sizeof(LNode_t));
	new_node->data	  = data;
	new_node->next	  = list->next;
	list->next		  = new_node;
	return 1;
}

int Length(LNode_t* list)
{
	if (IsEmpty(list))
		return 0;
	list = list->next;

	int len = 0;
	do
	{
		++len;
		list = list->next;
	} while (list);
	return len;
}

LNode_t* GetElem(LNode_t* list, int idx)
{
	if (IsEmpty(list))
		return NULL;
	list = list->next;

	for (int i = 0; i < idx; ++i)
	{
		list = list->next;
		if (list->next == NULL && i != idx - 1)
			return NULL;
	}
	return list;
}

LNode_t* LocateElem(LNode_t* list, int data)
{
	if (IsEmpty(list))
		return NULL;
	list = list->next;

	do
	{
		if (list->data == data)
			return list;
		else
			list = list->next;
	} while (list);
	return list;
}

int DeleteNode(LNode_t* list, int idx)
{
	if (IsEmpty(list))
		return 0;

	--idx;
	for (int i = 0; i < idx; ++i)
	{
		list = list->next;
		if (list->next == NULL && i != idx - 1)
			return 0;
	}
	LNode_t* tmp = list->next;
	list->next	 = list->next->next;
	free(tmp);
	return 1;
}

LNode_t* ReverseList(LNode_t* node, LNode_t* next_ptr)
{
	LNode_t* next = node->next;
	node->next	  = next_ptr;
	if (next == NULL)
	{
		return node;
	}
	node = ReverseList(next, node);
	return node;
}

void Reverse(LNode_t* head)
{
	LNode_t* list = head->next;
	LNode_t* tail;
	tail	   = ReverseList(list, NULL);
	head->next = tail;
}

int test()
{
	LNode_t	 list;
	LNode_t* head = &list;
	InitList(head);
	AppendNode(head, 5);
	AppendNode(head, 6);
	InsertNode(head, 7, 1);
	DeleteNode(head, 10);

	PrintList(head);

	printf("Len:%d\n", Length(head));
	LNode_t* tmp = LocateElem(head, 5);
	if (tmp != NULL)
		printf("data:%d\n", tmp->data);
	return 0;
}

void test_reverse()
{
	LNode_t* head = (LNode_t*)malloc(sizeof(LNode_t));
	InitList(head);
	for (int i = 0; i < 10; ++i)
		AppendNode(head, i);
	PrintList(head);

	Reverse(head);
	PrintList(head);
}

int main()
{
	// test();
	test_reverse();
	return 0;
}
