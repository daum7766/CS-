#include <stdio.h>
#include "StackA.h"
#include <iostream>		 //cout ��밡���ϰ�����
#include <string>


using namespace std;	//cout ��밡���ϰ� ����

stackClass::stackClass()		//������ �Լ�
{
	//Top = NULL;		//ž����Ʈ�� NULL�� ����
	//Count = 0;		//ī��Ʈ 0���� ����(��������)
}

stackClass::~stackClass()		//�Ҹ��� �Լ�
{
	//int Temp;
	//while (!IsEmpty())		//������� �ʴٸ� ��� ���Ѵ�.
	//	Temp = Pop();
}
bool stackClass::stackIsEmpty()		//����ִ��� Ȯ��
{
	//return bool(Top == NULL);		//top�� NULL���� Ȯ��
	return bool(L.IsEmpty());

}

void stackClass::Push(int Item)		//item���� ���ÿ� �����ϴ� �Լ�
{
	//Nptr NewTop = new node;		//���ο� ��� ����
	//NewTop->Data = Item;		//���ο� ��� ž�� �������� ����
	//NewTop->Next = Top;		//���ο� ��尡 ����Ű�� �����Ϳ� ž�� ����
	//Top = NewTop;		//ž�� ���ο� ���� �ٲ�
	//Count++;		//ī���� ����
	L.Insert(1, Item);
}

int stackClass::Pop()		//���� ž�� �����Ͱ��� ������.
{
	int Item;
	//if (IsEmpty())		//����ִٸ� �����Ҽ����ٰ� �˸�
	//	cout << "�󸮽�Ʈ�� �����Ҽ� �����ϴ�.\n";
	//else
	//{
	//	Count--;		//ī���� ����
	//	Nptr Temp = Top;		//������ ž��带 �������
	//	int Item = Temp->Data;	//�����ۿ� ������ �����Ͱ��� �������
	//	Top = Top->Next;		//ž�� ž�̰���Ű�� ������������ �ٲ�
	//	delete Temp;		//temp�� �ݳ���.
	//	return Item;		//item���� ������
	//}
	L.Delete(1);
	return 0;
}

int stackClass::stackLength()		//���ÿ� ���� �������� ������ ã�� �Լ�
{
	return L.Length();				//ī���� ���� ������.
}

int stackClass::bgoperator(char *op)		//�������� �Լ�
{
	int i,kk;	//for ��
	int a=0, b=0, v=0, s=0, re=NULL, nu=0;		//����ؾߵǴ� ����
	int box;
	
	cout << op << "�� ����ϰڽ��ϴ�.\n";
	for (i=0; op[i] != NULL; i++)		//���ڿ��� ���������� �ݺ�
	{

		if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/')
		{								//������ ��ȣ�� ������
			b = stackClass::GetTop(box);	//top���ִ°� b�� �������
				stackClass::Pop();		//���ÿ� �ִ°� ��
			a = stackClass::GetTop(box);	//top�� �ִ°� a���������
				stackClass::Pop();		//���ÿ� �ִ°� ��

			if (op[i] == '+')
			{
				v = a + b;				//�����Ѵ�.
			}
			if (op[i] == '-')
			{
				v = a - b;
			}
			if (op[i] == '*')
			{
				v = a * b;
			}
			if (op[i] == '/')
			{
				v = a / b;
			}
			stackClass::Push(v);		//������ ���� ���ÿ� �ٽ� Ǫ��

		}
		else if (op[i] == ' ')		//���� ������ �ƹ��͵� �����ʴ´�.
		{

		}
		else
		{

			if (op[i + 1] != ' '&&op[i+1] != '.')		//���� �迭�� ���Ⱑ �ƴ϶��
			{
				s = op[i] - '0';		//������� s�� �����Ѵ�.
				nu = nu + s;		//������� 10�踦 nu�� �����Ѵ�.
				nu = 10 * nu; //nu�� 10�踦 ���ش�.

			}
			else				//�����迭�� ������
			{
				s = op[i] - '0';		//������� s�� �����Ѵ�.

				if (op[i + 1] == '.')
				{

					i = i + 2;

				}

				nu = nu + s;		//nu�� s�� ���Ͽ� nu�� ����ִ´�.

				stackClass::Push(nu);		//nu���� ���ÿ� Ǫ���Ѵ�.
				nu = 0;		//nu���� 0���� �ʱ�ȭ�Ѵ�.
			}
		}
	}



	re = stackClass::GetTop(box);
	stackClass::Pop();

	return re;
}

int stackClass::GetTop(int& Item)
{
	int ab;
	ab = L.Retrieve(1, Item);
	return ab;
}