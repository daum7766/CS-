#include <stdio.h>		//��������� ����
#include "ListP.h"
#include <stdlib.h>
#include <SDKDDKVer.h>
#include <tchar.h>



void Init(listType *Lptr)		//�ʱ�ȭ �Լ�
{
	Lptr->Count = 0;		//����Ʈ�� ���̸� 0���� �ʱ�ȭ
	Lptr->Head = NULL;		//��� �����͸� NULL�� �ʱ�ȭ
}
bool IsEmpty(listType *Lptr)		//�� ����Ʈ���� �˾ƺ���
{return(Lptr->Count == 0);		//����Ʈ ���̰� 0�̸� �󸮽�Ʈ
}
void Insert(listType *Lptr, int Position, int Item)		//�����Լ�
{
	if ((Position > (Lptr->Count + 1)) || (Position < 1))
		printf("������ġ���� ������ �����ϴ�.\n"); //�̰ݵ� ������ġ ����
	else
	{
		Nptr p = (node *)malloc(sizeof(node));		//���Ե� ����� ���� Ȯ��
		p->Data = Item;		//������ �� ����9
		if (Position == 1)		//ù��ġ�� ������ ���
		{
			p->Next = Lptr->Head;		//���Գ�尡 ���� ù ��带 ����Ŵ
			Lptr->Head = p;		//��尡 ���� ��带 ����Ű��
		}
		else          //ù��ġ�� �ƴҰ��
		{
			Nptr Temp = Lptr->Head;		//��������͸� Temp�� ����
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;		//Temp�� �������� ��带 ����Ű��
			p->Next = Temp->Next;		//���Գ���� Next�� ����
			Temp->Next = p;		//������尡 ���Ե� ��带 ����Ű��
		}
		Lptr->Count += 1;		//����Ʈ ���̸� �ø�
	}
}

void Delete(listType *Lptr, int Position)
{
	int* p=0;
	if (IsEmpty(Lptr))
		printf("����Ʈ�� ����ֽ��ϴ�.\n");		//�� ����Ʈ���� �����䱸�� ����
	else if (Position > (Lptr -> Count) || (Position < 1))
		printf("������ ������ ������ϴ�.\n");		//������ġ�� ���� ������ ������ ���
	else
	{
		if (Position == 1)		//ù ��带 �����ϴ� ���
		{
			Nptr p = Lptr->Head;		//������ ��带 ����Ű�� �����͸� ���
			Lptr->Head = Lptr->Head->Next;		//��尡 ��° ��带 ����Ű��

		}
		else
		{
			Nptr Temp = Lptr->Head;
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;		//Temp�� �������� ��带 ����Ű��
			Nptr p = Temp->Next;		//������ ��带 ����Ű�� �����͸� ���
			Temp->Next = p->Next;		//���� ��尡 ������ ��� ���� ��带 ����Ű��
		}
		Lptr->Count -= 1;
		free(p);
	}
}

void Reverse(listType *Lptr)		//������ �Լ�
{
	int co=0;
	int item = 0;
	int kk;
	co = Lptr->Count;
	for (kk = 1; kk < co; kk++)
	{
		item = Retrieve(Lptr, co, item);
		Insert(Lptr, kk, item);
		Delete(Lptr, Lptr->Count);
	}
	
}
void Random_Append(listType *Lptr,int rp ,int rn)		//���������Լ�
{
	int ii;
	srand((unsigned)time(NULL));
	for (ii = 1; ii <= rn; ii++)
	{
		Insert(Lptr, rp, rand());
		rp = rp++;
	}
}

int Retrieve(listType *Lptr, int Position, int *ItemPtr)		//Ž���Լ�
{
	Nptr Temp = Lptr->Head;
	int xx = 1;
	while (Temp != NULL)
	{
		if (Position == xx)
		{
			break;
		}
		else
		{
			xx++;
			Temp = Temp->Next;
		}
	}
	if (xx > Lptr->Count)
	{
		ItemPtr = 0;
		return *ItemPtr;
	}
	else
	{
		ItemPtr = &Temp->Data;
		return *ItemPtr;
	}
}
void PrintList(listType *Lptr)		//ȭ������Լ�
{
	Nptr Temp = Lptr->Head;
	printf("����Ʈ�� : ");
	while (Temp != NULL)
	{
		printf("%d ->", Temp->Data);
		Temp = Temp->Next;
	}
	printf("NULL.\n");
}

int Length(listType *Lptr)		//����Ȯ�� �Լ�
{
	printf("����Ʈ�� ���̴� %d �Դϴ�.\n", Lptr->Count);
	return Lptr->Count;
}

void main()		//�����Լ�
{
	bool check = true;
	bool ch;
	int num;
	int InsertPosition;
	int InsertNum;
	int DeletePosition;
	int searchnum;
	int* box=0;
	int randNum;
	int randPositionNum;

	listType* mylist = (listType*)malloc(sizeof(listType));
	Init(mylist);
	printf("����Ʈ�� �����߽��ϴ�. \n�۾��ϰ� ���� ������ �������ּ���. \n");
	while (check)
	{
		printf("1.���� \n");
		printf("2.���� \n");
		printf("3.�˻� \n");
		printf("4.���� \n");
		printf("5.���������̱� \n");
		printf("6.����ֳ�Ȯ�� \n");
		printf("7.����Ȯ�� \n");
		printf("8.����Ʈ ��� \n");
		printf("9.���� \n");
		scanf_s("%d", &num);
		switch(num)
		{case 1:
			printf("������ ��ġ�� �������ּ���\n");
			scanf_s("%d", &InsertPosition);
			printf("������ ���� �������ּ��� \n");
			scanf_s("%d", &InsertNum);
			printf("\n");
			Insert(mylist, InsertPosition, InsertNum);
			break;
		case 2:
			printf("������ ��ġ�� �������ּ���\n");
			scanf_s("%d", &DeletePosition);
			printf("\n");
			Delete(mylist, DeletePosition);
			break;
		case 3:
			printf("�˻��ϰ� ���� ��ġ���� �������ּ���\n");
			scanf_s("%d", &searchnum);
			printf("\n");
			box=Retrieve(mylist, searchnum, box);
			if (box == 0)
			{
				printf("%d ��ġ�� �����Ͱ� �����ϴ�..\n", searchnum);
			}
			else
			{
				printf("%d�� ��ġ�� �ִ� ���� %d �Դϴ�. \n", searchnum, box);
			}
			break;
		case 4:
			Reverse(mylist);
			printf("����Ʈ�� �������� ��������ϴ�.\n");
			break;
		case 5:
			printf("������ ������ ������ �������ּ���.\n");
			scanf_s("%d", &randNum);
			printf("������ ������ ������ ��ġ�� �������ּ���\n");
			scanf_s("%d", &randPositionNum);
			printf("\n");
			Random_Append(mylist, randPositionNum ,randNum);
			break;
		case 6:
			ch=IsEmpty(mylist);
			if (ch == true)
			{
				printf("����Ʈ�� ����ֽ��ϴ�.\n");
			}
			else
			{
				printf("����Ʈ�� ������� �ʽ��ϴ�.\n");
			}
			break;
		case 7:
			Length(mylist);
			break;
		case 8:
			PrintList(mylist);
			break;
		case 9:
			check = false;
			break;
			}
		printf("\n");
	}
	//return;
}