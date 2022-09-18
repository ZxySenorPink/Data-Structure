#include "DynamicArray.h"

struct Person
{
	char* name;
	int age;
};

void personPrint(void* data)
{
	struct Person* p = (struct Person*)data;
	printf("Name: %-15s\ttage: %d\n", p->name, p->age);
}

int personCompare(void* data1, void* data2)
{
	if (data1 == NULL || data2 == NULL)
	{
		return;
	}
	
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	//if (p1->name == p2->name && p1->age == p2->age)
	//{
	//	return 1;
	//}

	//return 0;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}


int main()
{
	struct DynamicArray *StrawHatPirates = init_DynamicArray(5);
	
	//准备数据
	struct Person p1 = { "MONKEY·D·LUFFY" , 19 };
	struct Person p2 = { "RORONOA ZORO" , 21 };
	struct Person p3 = { "VINSMOKE SANJI" , 19 };
	struct Person p4 = { "NAMI" , 20 };
	struct Person p5 = { "USOPP" , 19 };
	struct Person p6 = { "CHOPPER" , 17 };
	struct Person p7 = { "NICO ROBIN" , 30 };
	struct Person p8 = { "FRANKY" , 36 };
	struct Person p9 = { "BROOK" , 90 };
	struct Person p10 = { "JINBE" , 46 };
	struct Person p11 = { "VIVI" , 18 };
	struct Person p12 = { "YAMATO",28 };

	printf("Before sailing：Capacity：%d  Members：%d\n", StrawHatPirates->capacity, StrawHatPirates->size);

	//插入数据
	insert_DynamicArray(StrawHatPirates, 0, &p1);
	insert_DynamicArray(StrawHatPirates, 1, &p2);
	insert_DynamicArray(StrawHatPirates, 2, &p3);
	insert_DynamicArray(StrawHatPirates, 3, &p4);
	insert_DynamicArray(StrawHatPirates, 4, &p5);
	insert_DynamicArray(StrawHatPirates, 5, &p6);
	insert_DynamicArray(StrawHatPirates, 6, &p7);
	insert_DynamicArray(StrawHatPirates, 7, &p8);
	insert_DynamicArray(StrawHatPirates, 8, &p9);
	insert_DynamicArray(StrawHatPirates, 9, &p10);
	insert_DynamicArray(StrawHatPirates, 10, &p11);
	insert_DynamicArray(StrawHatPirates, 11, &p12);

	printf("\nAfter sailing：Capacity：%d  Members：%d\n\n", StrawHatPirates->capacity, StrawHatPirates->size);
	//遍历数据
	foreach_DynamicArray(StrawHatPirates, personPrint);

	//测试删除 按位置删除
	removeByPos_DynamicArray(StrawHatPirates, 10);
	printf("\n-----------------------------------------------\n");
	foreach_DynamicArray(StrawHatPirates, personPrint);
	printf("\nAfter leaving：Capacity：%d  Members：%d\n\n", StrawHatPirates->capacity, StrawHatPirates->size);
	
	//测试删除 按数据删除
	removeByData_DynamicArray(StrawHatPirates, &p12, personCompare);
	printf("\n-----------------------------------------------\n");
	foreach_DynamicArray(StrawHatPirates, personPrint);
	printf("\nAfter leaving：Capacity：%d  Members：%d\n\n", StrawHatPirates->capacity, StrawHatPirates->size);

	//销毁数组
	destroy_DynamicArray(StrawHatPirates);
	StrawHatPirates = NULL;

	system("pause");

	return EXIT_SUCCESS;
}