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

//初始化链式队列
LinkQueue init_LinkQueue();

//入队
void push_LinkQueue(LinkQueue queue, void* data);

//出队
void pop_LinkQueue(LinkQueue queue);

//返回队列大小
int size_LinkQueue(LinkQueue queue);

//判断队列是否为空
int isEmpty_LinkQueue(LinkQueue queue);

//返回队头元素
void* front_LinkQueue(LinkQueue queue);

//返回队尾元素
void* back_LinkQueue(LinkQueue queue);

//销毁队列
void destroy_LinkQueue(LinkQueue queue);