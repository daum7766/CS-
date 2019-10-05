#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "ListP.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <ctime>


using namespace std;

listClass::listClass()		//������ �Լ�
{
	Count = 0;				//����Ʈ�� ���̸� 0���� �ʱ�ȭ
	Head = NULL;			// ��带 NULL�� �ʱ�ȭ
}
bool listClass::IsEmpty()	// �� ����Ʈ���� Ȯ���ϴ� �Լ�
{
	return (Count == 0);	//�迭���̰� 0�̸� True�� ��ȯ
}

int listClass::Length()
{
	return Count;
}

void listClass::PrintList()
{
	Nptr Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->Data <<"->";
		Temp = Temp->Next;
	}
	cout << "NULL.\n";

}

void listClass::Insert(int Position, int Item)
{
	if ((Position > (Count + 1)) || (Position < 1))
		cout <<"������ġ���� ������ �����ϴ�.\n"; //�̰ݵ� ������ġ ����
	else
	{
		Nptr p = (node *)malloc(sizeof(node));		//���Ե� ����� ���� Ȯ��
		p->Data = Item;		//������ �� ����9
		if (Position == 1)		//ù��ġ�� ������ ���
		{
			p->Next = Head;		//���Գ�尡 ���� ù ��带 ����Ŵ
			Head = p;		//��尡 ���� ��带 ����Ű��
		}
		else          //ù��ġ�� �ƴҰ��
		{
			Nptr Temp = Head;		//��������͸� Temp�� ����
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;		//Temp�� �������� ��带 ����Ű��
			p->Next = Temp->Next;		//���Գ���� Next�� ����
			Temp->Next = p;		//������尡 ���Ե� ��带 ����Ű��
		}
		Count += 1;		//����Ʈ ���̸� �ø�
	}
}

void listClass::Random_Append(int rp, int rn)
{
	int ii;
	srand(time(NULL));
	for (ii = 1; ii <= rn; ii++)
	{
		Insert(rp, rand());
		rp = rp++;
	}
}

void listClass::Reverse()
{
	int co = 0;
	int item = 0;
	int kk;
	co = Count;
	for (kk = 1; kk < co; kk++)
	{
		item = listClass::Retrieve(co, item);
		listClass::Insert(kk, item);
		listClass::Delete(Count);
	}

}

void listClass::DeDuplicate()
{
	int item1 = 0;
	int item2 = 0;
	int kk;
	int ii;
	for (kk = 1; kk <= Count; kk++)
	{
		item1 = listClass::Retrieve(kk, item1);
		for (ii = 1; ii <= Count; ii++)
		{
			item2= listClass::Retrieve(ii, item2);
			if (item1 == item2)
			{
				if (kk != ii)
				{
					listClass::Delete(ii);
				}

			}

		}
	}
}

int listClass::Retrieve(int Position, int& Item)
{
	Nptr Temp = Head;
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
		if (xx > Count)
		{
			Item = 0;
			return Item;
		}
		else
		{
			Item = Temp->Data;
			return Item;
		}
}


void listClass::Delete(int Position)		//�����Լ�
{
	int *p=0;
	Nptr Temp=0;
	if (IsEmpty())
		cout << "�󸮽�Ʈ�� �����Ҽ� �����ϴ�.";		//�� ����Ʈ�� ���� �䱸�� ����
	else if ((Position > Count) || (Position < 1))
		cout << "�����Ϸ��� ��ġ�� ������ ������ϴ�.";		//������ġ�� ������ ������ ���
	else
	{
		if (Position == 1)						//������ ��尡 ù ����� ���
		{
			Nptr p = Head;						//������ ��带 ����Ű�� �����͸� ���
			Head = Head->Next;					//��尡 ��° ��带 ����Ű��
		}
		else									//������尡 ù ��尡 �ƴ� ���
		{
			Temp = Head;
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;				//Temp�� ������ ����� ���� ���� �̵�
			Nptr p = Temp->Next;				//������ ��带 ����Ű�� �����͸� ���
			Temp->Next = p -> Next;				//������尡 ������ ��� ������ ����Ű��
		}
		Count -= 1;								//����Ʈ ���̸� ����
		delete(p);								//�޸� ���� �ݳ�
	}
}

listClass::~listClass()
{
	while (!IsEmpty())							// �Ҹ��� �Լ�
		Delete(1);								// ����Ʈ�� ������ �� ������
}
listClass::listClass(const listClass& L)		// ���� ������ �Լ�
{
	Count = L.Count;							//�ϴ� ����Ʈ ������ �����ϰ�
	if (L.Head == NULL)
		Head = NULL;							//�Ѿ�°� �󸮽�Ʈ��� �ڽŵ� �󸮽�Ʈ
	else
	{
		Head = new node;						//�� ����Ʈ�� �ƴ϶�� �ϴ� �� ��带 �����
		Head->Data = L.Head->Data;				//������ ����
		Nptr Temp1 = Head;						//Temp1�� �纻�� ��ȸ�ϴ� ������
		for (Nptr Temp2 = L.Head->Next;
			Temp2 != NULL; Temp2 = Temp2 -> Next)
		{
			Temp1->Next = new node;				//�纻�� ���� ��忡 �� ��带 ����
			Temp1 = Temp1->Next;				//�� ���� �̵�
			Temp1->Data = Temp2->Data;			//�� ��忡 ���� �����͸� ����
		}
		Temp1->Next = NULL;						//�纻�� ������ ����� Next�� ���� ����
	}
}

