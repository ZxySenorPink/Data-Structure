#include "SeqStack.h"

struct Person
{
	char* name;
	int age;
};

int main()
{
	SeqStack StrawHatPirates = init_SeqStack();

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

	printf("Before sailing：Members：%d\n\n", size_SeqStack(StrawHatPirates));

	//入栈
	push_SeqStack(StrawHatPirates, &p1);
	push_SeqStack(StrawHatPirates, &p2);
	push_SeqStack(StrawHatPirates, &p3);
	push_SeqStack(StrawHatPirates, &p4);
	push_SeqStack(StrawHatPirates, &p5);
	push_SeqStack(StrawHatPirates, &p6);
	push_SeqStack(StrawHatPirates, &p7);
	push_SeqStack(StrawHatPirates, &p8);
	push_SeqStack(StrawHatPirates, &p9);
	push_SeqStack(StrawHatPirates, &p10);
	push_SeqStack(StrawHatPirates, &p11);
	push_SeqStack(StrawHatPirates, &p12);

	printf("After sailing：Members：%d\n\n", size_SeqStack(StrawHatPirates));

	//遍历数据
	while (isEmpty_SeqStack(StrawHatPirates) == 0)
	{
		//返回栈顶元素
		struct Person* person = top_SeqStack(StrawHatPirates);

		//打印栈顶元素
		printf("Name: %-15s\ttage: %d\n", person->name, person->age);

		//出栈
		pop_SeqStack(StrawHatPirates);
	}

	//销毁顺序栈
	destroy_SeqStack(StrawHatPirates);
	StrawHatPirates = NULL;

	system("pause");
	return EXIT_SUCCESS;
}