#include <stdio.h>
#include <iostream>		 //cout ��밡���ϰ�����
#include "head.h"
#include <string>
#define Max 100

using namespace std;	//cout ��밡���ϰ� ����


void main()
{
	bool end = true;		//��ü���α׷� ���ắ��
	int *addr[Max];			//�迭 �ּҸ� �������ִ� ����
	Heapclass *myHeap = new Heapclass;		//Ŭ���� ����
	Heapclass::Heapclass();					//Ŭ���� �ʱ�ȭ
	while (end)				//��ü ���α׷� �ݺ�
	{

		int num = false;		//����ġ ����
		int bcount = 0;			//�迭 ī����(���� ��� ����ִ���)

		string list[] = { "����", "�ı�", "����", "����", "���� ����", "���� ����", "�θ� ���", "�ڽ����", "�����","����" };
		cout << "\n******** �޴� ********\n";
		for (int i = 1; i <= 10; i++)
		{
			cout << i << "." << list[i - 1] << "\n";
		}		// for�� ����
		cout << "\n�޴��� ������ �ּ���.\n";
		cin >> num;

		switch (num)
		{
		case 1:		//����
			if (acount == 0)
			{
				addr[acount] = myHeap->HeapCreate();
				acount++;
			}
			else
			{
				cout << "�迭�� �̹� �����Ǿ����ϴ�.";
			}
			break;
		case 2:		//�ı�
			if (acount == 0)
			{
				cout << "������ �迭�� �����ϴ�.\n";
			}
			else if (acount == 1)
			{
				myHeap->Destroy(addr[acount-1]);
				cout << "�迭�� �����߽��ϴ�.\n";
				acount--;
			}

			break;
		case 3:		//����
			int ad;		//������ ������ ����
			if (acount == 0)
			{
				cout << "������ �迭�� �����ϴ�.";
			}
			else
			{
				cout << "������ ���� �Է����ּ���\n";
				cin >> ad;
				myHeap->Add(addr[acount - 1], ad);
				cout << "�����͸� �Է��߽��ϴ�.\n";
			}
			break;
		case 4:		//����
			if (acount == 0)
			{
				cout << "������ �迭�� �����ϴ�.";
			}
			else
			{
				myHeap->Remove(addr[acount - 1]);
			}
			break;
		case 5:		//���� ����
			if (acount == 0)
			{
				cout << "������ �迭�� �����ϴ�.";
			}
			else
			{
				myHeap->MultiAdd(addr[acount - 1]);

			}
			break;
		case 6:		//���߻���
			if (acount == 0)
			{
				cout << "������ �迭�� �����ϴ�.";
			}
			else
			{
				myHeap->MultiRemove(addr[acount - 1]);
			}
			break;
		case 7:		//�θ� ���
			if (acount == 0)
			{
				cout << "����� �迭�� �����ϴ�.";
			}
			else
			{
				int paprint;		//���°�� �θ� ������� ���ϴ� ����
				cout << "���° ����� �θ��带 ������� �Է����ּ���\n";
				cin >> paprint;
				myHeap->PrintParent(addr[acount - 1], paprint);
			}
			break;
		case 8:		//�ڽ� ���
			if (acount == 0)
			{
				cout << "����� �迭�� �����ϴ�.";
			}
			else
			{
				int child;		//���° ����� �ڽĳ�带 ������� ���ϴ� ����
				cout << "���° ����� �ڽĳ�带 ������� �Է����ּ���\n";
				cin >> child;
				myHeap->PrintChild(addr[acount - 1], child);
			}
			break;
		case 9:		//�� ���
			if (acount == 0)
			{
				cout << "����� �迭�� �����ϴ�.";
			}
			else
			{
				myHeap->PrintHeap(addr[acount - 1]);
			}
			break;
		case 10:		//����
			end = false;
			break;

		}		// ����ġ�� ����
	}		//while ����
}		// �����Լ� ����

