#include "DynamicArray.h"

//初始化数组
struct DynamicArray* init_DynamicArray(int capacity)
{	
	if (capacity <= 0)
	{
		return NULL;
	}

	//给数组分配空间
	struct DynamicArray* dArray = malloc(sizeof(struct DynamicArray));
	if (dArray == NULL)
	{
		return NULL;
	}

	//给数组元素初始化
	dArray->addr = malloc(sizeof(void*) * capacity);
	dArray->capacity = capacity;
	dArray->size = 0;
	
	return dArray;
}

//插入元素
void insert_DynamicArray(struct DynamicArray* dArray, int pos, void* data)
{
	if (dArray == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//无效位置 -> 尾插
	if (pos < 0 || pos > dArray->size)
	{
		pos = dArray->size;
	}
	//判断是否满了，如果满了 则需要动态扩展
	if (dArray->capacity == dArray->size)
	{
		//1、计算新空间的大小
		int newCapacity = dArray->capacity * 2;
		
		//2、创建新空间
		void** newSpace = malloc(sizeof(void*) * newCapacity);

		//3、将原有数据拷贝到新空间下
		memcpy(newSpace, dArray->addr, sizeof(void*) * dArray->capacity);

		//4、释放原内存空间
		free(dArray->addr);

		//5、更新新空间指向
		dArray->addr = newSpace;

		//6、更新新容量
		dArray->capacity = newCapacity;
	}
	//插入新元素

	//移动元素
	for (int i = dArray->size - 1; i >= pos; i--)
	{
		//数据向后移动
		dArray->addr[i + 1] = dArray->addr[i];
	}

	//将新元素插入到指定位置上
	dArray->addr[pos] = data;
	
	//更新大小
	dArray->size++;

}

//遍历数组
void foreach_DynamicArray(struct DynamicArray* dArray, void(*Print)(void*))
{
	if (dArray == NULL)
	{
		return;
	}
	if (Print == NULL)
	{
		return;
	}

	for (int i = 0; i < dArray->size; i++)
	{
		Print(dArray->addr[i]);
	}
}

//按位置删除数组元素
void removeByPos_DynamicArray(struct DynamicArray* dArray, int pos)
{
	if (dArray == NULL)
	{
		return;
	}
	if (pos < 0 || pos > dArray->size)
	{
		return;
	}

	//数据前移
	for (int i = pos; i < dArray->size; i++)
	{
		dArray->addr[i] = dArray->addr[i + 1];
	}

	//更新数组大小
	dArray->size--;
}

//按数据删除数组元素
void removeByData_DynamicArray(struct DynamicArray* dArray, void* data, int(*Compare)(void*, void*))
{
	if (dArray == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (Compare == NULL)
	{
		return;
	}

	for (int i = 0; i < dArray->size; i++)
	{
		if (Compare(dArray->addr[i], data))
		{
			removeByPos_DynamicArray(dArray, i);
			break;
		}
	}
}

//销毁数组
void destroy_DynamicArray(struct DynamicArray* dArray)
{
	if (dArray == NULL)
	{
		return;
	}

	if (dArray->addr != NULL)
	{
		free(dArray->addr);
		dArray->addr = NULL;
	}

	free(dArray);
	dArray = NULL;
}