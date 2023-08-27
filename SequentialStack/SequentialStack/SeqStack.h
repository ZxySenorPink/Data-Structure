#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _STACK_MAX_SIZE_ 1024

typedef void* SeqStack;

struct sys_SeqStack
{
	void* data[_STACK_MAX_SIZE_];
	int size;
};

//初始化栈
SeqStack init_SeqStack();

//入栈
void push_SeqStack(SeqStack stack, void* data);

//弹栈
void pop_SeqStack(SeqStack stack);

//返回栈顶元素
void* top_SeqStack(SeqStack stack);

//返回栈的大小
int size_SeqStack(SeqStack stack);

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack);

//销毁栈
void destroy_SeqStack(SeqStack stack);
