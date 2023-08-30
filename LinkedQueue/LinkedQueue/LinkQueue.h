#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* LinkQueue;

struct LinkQueueNode
{
	void* next;
};

struct sys_LinkQueue
{
	struct LinkQueueNode head;
	struct LinkQueueNode* tail;
	int size;
};

//��ʼ����ʽ����
LinkQueue init_LinkQueue();

//���
void push_LinkQueue(LinkQueue queue, void* data);

//����
void pop_LinkQueue(LinkQueue queue);

//���ض��д�С
int size_LinkQueue(LinkQueue queue);

//�ж϶����Ƿ�Ϊ��
int isEmpty_LinkQueue(LinkQueue queue);

//���ض�ͷԪ��
void* front_LinkQueue(LinkQueue queue);

//���ض�βԪ��
void* back_LinkQueue(LinkQueue queue);

//���ٶ���
void destroy_LinkQueue(LinkQueue queue);