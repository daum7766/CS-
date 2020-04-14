#include <stdio.h>
#include <iostream>		 //cout ��밡���ϰ�����
#include "head.h"
#include <string>
#define Max 100

using namespace std;	//cout ��밡���ϰ� ����


Heapclass::Heapclass()		//������ �Լ�
{
	count = 0;			
}
int* Heapclass::HeapCreate()						//1.����
{

	int *addr = new int[Max];
	cout << "�迭�� �����߽��ϴ�. \n";
	cout << "�迭�� �ִ�ũ��� 100�Դϴ�.\n";
	return addr;

}

void Heapclass::Destroy(int *addr )					//2.�ı�
{

		delete addr;
		count = 0;

}
void Heapclass::Add(int *addr,int Data)				//3.����
{
	int Current = count;
	int Parent = (Current - 1) / 2;
	int dat;
	*(addr + count) = Data;
	while ((Current != 0) && (*(addr + Current) > *(addr + Parent)))
	{
		int dat = *(addr + Parent);
		*(addr + Parent) = *(addr + Current);
		*(addr + Current) = dat;
		Current = Parent;
		Parent = (Current - 1) / 2;
	}
	count++;

}
void Heapclass::Remove(int *addr)						//4.����
{
		int ret = *addr;
		*(addr) = *(addr + (count - 1));
		count--;
		cout << ret << "�� �����߽��ϴ�.\n";
		DownHeap(addr, 0);

}
void Heapclass::MultiAdd(int *addr)			//5.���߻���
{
		int in = 0;		//�Է��� ������ ����
		int data = 0;	//�Է¹޴� ������
		cout << "��� �����͸� �������� �Է����ּ���\n";
		cin >> in;
		if (in <= Max - count)
		{
			for (int i = 0; i < in; i++)
			{
				cout << i + 1 << "��° �����͸� �Է����ּ���\n";
				cin >> data;
				Add(addr, data);
			}
			cout << "��� �����͸� �Է��߽��ϴ�.\n";
		}
		else
		{
			cout << "�ִ밹���� �ʰ��߽��ϴ�.\n";
		}


}
void Heapclass::MultiRemove(int *addr)	//6.���߻���
{
		int Number;
		cout << "������ ����� ������ �Է����ּ���\n";
		cin >> Number;
		if (Number <= count)
		{
			for (int i = 0; i < Number; i++)
			{
				Remove(addr);
			}

		}
		else {
			cout << "�Է��� ���� �ѳ���� �������� �����ϴ�.";
		}
}
void Heapclass::PrintParent(int *addr, int Number)	//7.�θ����
{


		int Parent;
		if (Number == 0)
		{
			cout << "�θ��尡 �����ϴ�.\n";
		}
		else if (Number > count - 1)
		{
			cout << "������� �����Ͱ� �����ϴ�\n";
		}
		else
		{
			Parent = (Number - 1) / 2;
			cout << *(addr + Parent) << "(" << Parent << ")" << "->" << *(addr + Number) << "(" << Number << ")";
		}
}
void Heapclass::PrintChild(int *addr, int Number)		//8.�ڽĳ�����
{

		if (Number > count - 1)
		{
			cout << "���� ������ ��忡�� �����Ͱ� �����ϴ�.\n";
		}
		else
		{

			int LChild;
			int RChild;
			LChild = (Number * 2) + 1;
			RChild = LChild + 1;
			if (LChild > count - 1)
			{
				cout << "�������� �ڽĳ��� �����ϴ�\n";
			}
			else if (RChild > count - 1)
			{
				cout << *(addr + LChild) << "(" << LChild << ")" << "<-" << *(addr + Number) << "(" << Number << ")" << "->" << "RChild ����";
			}
			else
			{
				cout << *(addr + LChild) << "(" << LChild << ")" << "<-" << *(addr + Number) << "(" << Number << ")" << "->" << *(addr + RChild) << "(" << RChild << ")";
			}
		}

}
void Heapclass::PrintHeap(int *addr)					//9.�� ���
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			cout << *(addr + i) << "(" << i << "�� ���" << ") ";
		}
		cout << "\n����� ������" << count << "���Դϴ�.\n";
	}
	else
	{
		cout << "�迭�� �����Ͱ� �����ϴ�.";
	}

}

void Heapclass::DownHeap(int *addr, int Current)	//�ٿ� ��
{
	int LChild = (Current * 2) + 1; ;
	int RChild = LChild + 1;
	int dat;
	if (RChild >count)
	{
		if (LChild > count)
		{
			//������ ������������
		}
		else		//LChild�� count���� ���ų� ������
		{
			if (*(addr + Current)<*(addr + LChild))
			{
				dat = *(addr + Current);
				*(addr + Current) = *(addr + LChild);
				*(addr + LChild) = dat;
				DownHeap(addr, LChild);
			}
		}
	}
	else if (*(addr + LChild)>*(addr + RChild))
	{
		if (*(addr + Current)<*(addr + LChild))
		{
			dat = *(addr + Current);
			*(addr + Current) = *(addr + LChild);
			*(addr + LChild) = dat;
			DownHeap(addr, LChild);
		}
	}
	else if (*(addr + LChild)<*(addr + RChild))
	{
		if (*(addr + Current)<*(addr + RChild))
		{
			dat = *(addr + Current);
			*(addr + Current) = *(addr + RChild);
			*(addr + RChild) = dat;
			DownHeap(addr, RChild);
		}
	}

	
}