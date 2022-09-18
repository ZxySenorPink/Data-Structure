#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DynamicArray
{
	void** addr;     //维护真实创建在堆区的数组的指针
	
	int capacity;   //数组容量
	
	int size;       //数组大小
};

//初始化数组
struct DynamicArray* init_DynamicArray(int capacity);

//插入元素
void insert_DynamicArray(struct DynamicArray* array, int pos, void* data);

//遍历数组
void foreach_DynamicArray(struct DynamicArray* array, void(*Print)(void*));

//按位置删除数组元素
void removeByPos_DynamicArray(struct DynamicArray* array, int pos);

//按数据删除数组元素
void removeByData_DynamicArray(struct DynamicArray* array, void* data, int(*Compare)(void*, void*));

//销毁数组
void destroy_DynamicArray(struct DynamicArray* array);