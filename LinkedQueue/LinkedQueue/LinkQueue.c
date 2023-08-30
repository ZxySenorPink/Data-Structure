#include "LinkQueue.h"

//初始化链式队列
LinkQueue init_LinkQueue()
{
	struct sys_LinkQueue* queue = malloc(sizeof(struct sys_LinkQueue));
	
	if (queue == NULL)
	{
		return NULL;
	}
	
	queue->head.next = NULL;
	queue->tail = &queue->head;
	queue->size = 0;
	
	return queue;
}

//入队  本质：链表尾插
void push_LinkQueue(LinkQueue queue, void* data)
{
	if (queue == NULL || data == NULL)
	{
		return;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;
	struct LinkQueueNode* node = data;

	//更改指针指向
	sys_linkqueue->tail->next = node;
	node->next = NULL;

	//更新新的尾节点
	sys_linkqueue->tail = node;

	sys_linkqueue->size++;
}

//出队  本质：链表头删
void pop_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	if (sys_linkqueue->size == 0)
	{
		return;
	}

	//只有一个数据的时候要将尾节点还原到头
	if (sys_linkqueue->size == 1)
	{
		sys_linkqueue->head.next = NULL;
		sys_linkqueue->tail = &sys_linkqueue->head;
		sys_linkqueue->size--;
		return;
	}

	//记录第一个有数据的节点
	struct LinkQueueNode* node = sys_linkqueue->head.next;

	//更改指针指向
	sys_linkqueue->head.next = node->next;

	sys_linkqueue->size--;
}

//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->size;
}

//判断队列是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->size == 0;
}

//返回队头元素
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->head.next;
}

//返回队尾元素
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->tail;
}

//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	free(queue);
	queue = NULL;

}