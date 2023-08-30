#include "LinkQueue.h"

//��ʼ����ʽ����
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

//���  ���ʣ�����β��
void push_LinkQueue(LinkQueue queue, void* data)
{
	if (queue == NULL || data == NULL)
	{
		return;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;
	struct LinkQueueNode* node = data;

	//����ָ��ָ��
	sys_linkqueue->tail->next = node;
	node->next = NULL;

	//�����µ�β�ڵ�
	sys_linkqueue->tail = node;

	sys_linkqueue->size++;
}

//����  ���ʣ�����ͷɾ
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

	//ֻ��һ�����ݵ�ʱ��Ҫ��β�ڵ㻹ԭ��ͷ
	if (sys_linkqueue->size == 1)
	{
		sys_linkqueue->head.next = NULL;
		sys_linkqueue->tail = &sys_linkqueue->head;
		sys_linkqueue->size--;
		return;
	}

	//��¼��һ�������ݵĽڵ�
	struct LinkQueueNode* node = sys_linkqueue->head.next;

	//����ָ��ָ��
	sys_linkqueue->head.next = node->next;

	sys_linkqueue->size--;
}

//���ض��д�С
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->size;
}

//�ж϶����Ƿ�Ϊ��
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->size == 0;
}

//���ض�ͷԪ��
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->head.next;
}

//���ض�βԪ��
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct sys_LinkQueue* sys_linkqueue = queue;

	return sys_linkqueue->tail;
}

//���ٶ���
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	free(queue);
	queue = NULL;

}