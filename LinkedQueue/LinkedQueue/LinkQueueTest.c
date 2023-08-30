#include "LinkQueue.h"

struct Person
{
	void* addr;
	char* name;
	int age;
};

int main()
{
	LinkQueue StrawHatPirates = init_LinkQueue();

	//׼������
	struct Person p1 = { NULL, "MONKEY��D��LUFFY" , 19 };
	struct Person p2 = { NULL, "RORONOA ZORO" , 21 };
	struct Person p3 = { NULL, "VINSMOKE SANJI" , 19 };
	struct Person p4 = { NULL, "NAMI" , 20 };
	struct Person p5 = { NULL, "USOPP" , 19 };
	struct Person p6 = { NULL, "CHOPPER" , 17 };
	struct Person p7 = { NULL, "NICO ROBIN" , 30 };
	struct Person p8 = { NULL, "FRANKY" , 36 };
	struct Person p9 = { NULL, "BROOK" , 90 };
	struct Person p10 = { NULL, "JINBE" , 46 };
	struct Person p11 = { NULL, "VIVI" , 18 };
	struct Person p12 = { NULL, "YAMATO",28 };

	printf("Before sailing��Members��%d\n\n", size_LinkQueue(StrawHatPirates));

	//���
	push_LinkQueue(StrawHatPirates, &p1);
	push_LinkQueue(StrawHatPirates, &p2);
	push_LinkQueue(StrawHatPirates, &p3);
	push_LinkQueue(StrawHatPirates, &p4);
	push_LinkQueue(StrawHatPirates, &p5);
	push_LinkQueue(StrawHatPirates, &p6);
	push_LinkQueue(StrawHatPirates, &p7);
	push_LinkQueue(StrawHatPirates, &p8);
	push_LinkQueue(StrawHatPirates, &p9);
	push_LinkQueue(StrawHatPirates, &p10);
	push_LinkQueue(StrawHatPirates, &p11);
	push_LinkQueue(StrawHatPirates, &p12);

	printf("After sailing��Members��%d\n\n", size_LinkQueue(StrawHatPirates));

	//��������
	while (isEmpty_LinkQueue(StrawHatPirates) == 0)
	{
		//���ض�ͷԪ��
		struct Person* front_person = front_LinkQueue(StrawHatPirates);
		//��ӡ��ͷԪ��
		printf("Name: %-15s\ttage: %d\n", front_person->name, front_person->age);

		//���ض�βԪ��
		struct Person* back_person = back_LinkQueue(StrawHatPirates);
		//��ӡ��βԪ��
		printf("Name: %-15s\ttage: %d\n\n", back_person->name, back_person->age);

		//����
		pop_LinkQueue(StrawHatPirates);
	}

	//����˳��ջ
	destroy_LinkQueue(StrawHatPirates);
	StrawHatPirates = NULL;

	system("pause");
	return EXIT_SUCCESS;
}