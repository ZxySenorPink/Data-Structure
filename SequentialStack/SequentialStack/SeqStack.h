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

//��ʼ��ջ
SeqStack init_SeqStack();

//��ջ
void push_SeqStack(SeqStack stack, void* data);

//��ջ
void pop_SeqStack(SeqStack stack);

//����ջ��Ԫ��
void* top_SeqStack(SeqStack stack);

//����ջ�Ĵ�С
int size_SeqStack(SeqStack stack);

//�ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack stack);

//����ջ
void destroy_SeqStack(SeqStack stack);
