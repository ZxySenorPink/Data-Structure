#include "SeqStack.h"

//初始化栈
SeqStack init_SeqStack()
{
	struct sys_SeqStack* stack = malloc(sizeof(struct sys_SeqStack));
	if (stack == NULL)
	{
		return NULL;
	}

	memset(stack->data, 0, sizeof(void*) * _STACK_MAX_SIZE_);
	stack->size = 0;

	return stack;
}

//入栈
void push_SeqStack(SeqStack stack, void* data)
{
	if (stack == NULL || data == NULL)
	{
		return;
	}

	struct sys_SeqStack* SequentialStack = stack;

	if (SequentialStack->size == _STACK_MAX_SIZE_)
	{
		return;
	}

	SequentialStack->data[SequentialStack->size] = data;
	SequentialStack->size++;
}

//弹栈
void pop_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	struct sys_SeqStack* SequentialStack = stack;

	if (SequentialStack->size == 0)
	{
		return;
	}

	SequentialStack->data[SequentialStack->size - 1] = NULL;
	SequentialStack->size--;
}

//返回栈顶元素
void* top_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	struct sys_SeqStack* SequentialStack = stack;

	if (SequentialStack->size == 0)
	{
		return NULL;
	}
	return SequentialStack->data[SequentialStack->size - 1];
}

//返回栈的大小
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct sys_SeqStack* SequentialStack = stack;
	return SequentialStack->size;
}

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct sys_SeqStack* SequentialStack = stack;
	return SequentialStack->size == 0;
}

//销毁栈
void destroy_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}
