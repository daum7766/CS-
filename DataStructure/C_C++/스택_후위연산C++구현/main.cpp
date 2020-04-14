#pragma once
#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <ctime>
#include "ListP.h"
#include "StackA.h"
#include <string>
#define max 20


using namespace std;

void main()		//�����Լ�
{
	int firstchoise = true;
	while (firstchoise)
	{


	int cppchoice = 0;



	cout << "1.���Ḯ��Ʈ\n";
	cout << "2.����\n";
	cout << "3.����\n";
	cin >> cppchoice;
	cout << "\n\n";

	switch (cppchoice)
	{
	case 1:
	{
		bool listcheck = true;
		bool ch;
		int num;
		int InsertPosition;
		int InsertNum;
		int DeletePosition;
		int searchnum;
		int box = 0;
		int len;
		int randNum;
		int randPositionNum;

		listClass* mylist = new listClass();
		listClass::listClass();
		cout << "����Ʈ�� �����߽��ϴ�. \n�۾��ϰ� ���� ������ �������ּ���. \n\n";
		while (listcheck)
		{
			cout << "1.���� \n";
			cout << "2.���� \n";
			cout << "3.�˻� \n";
			cout << "4.���� \n";
			cout << "5.���������̱� \n";
			cout << "6.����ֳ�Ȯ�� \n";
			cout << "7.����Ȯ�� \n";
			cout << "8.����Ʈ ��� \n";
			cout << "9.�ߺ�������� \n";
			cout << "10.������ ���ư��� \n";
			cin >> num;
			cout << "\n";

			switch (num)
			{
			case 1:
				cout << "������ ��ġ�� �������ּ���\n";
				cin >> InsertPosition;
				cout << "������ ���� �������ּ��� \n";
				cin >> InsertNum;
				cout << "\n";
				mylist->Insert(InsertPosition, InsertNum);
				break;
			case 2:
				cout << "������ ��ġ�� �������ּ���\n";
				cin >> DeletePosition;
				cout << "\n";
				mylist->Delete(DeletePosition);
				break;
			case 3:
				cout << "�˻��ϰ� ���� ��ġ���� �������ּ���\n";
				cin >> searchnum;
				cout << "\n";
				box = mylist->Retrieve(searchnum, box);
				if (box == 0)
				{
					cout << searchnum << "��ġ�� �����Ͱ� �����ϴ�..\n";
				}
				else
				{
					cout << searchnum << "�� ��ġ�� �ִ� ���� " << box << "�Դϴ�. \n";
				}
				break;
			case 4:
				mylist->Reverse();
				cout << "����Ʈ�� �������� ��������ϴ�.\n";
				break;
			case 5:
				cout << "������ ������ ������ �������ּ���.\n";
				cin >> randNum;
				cout << "������ ������ ������ ��ġ�� �������ּ���\n";
				cin >> randPositionNum;
				cout << "\n";
				mylist->Random_Append(randPositionNum, randNum);
				break;
			case 6:
				ch = mylist->IsEmpty();
				if (ch == true)
				{
					cout << "����Ʈ�� ����ֽ��ϴ�.\n";
				}
				else
				{
					cout << "����Ʈ�� ������� �ʽ��ϴ�.\n";
				}
				break;
			case 7:
				len = mylist->Length();
				cout << "����Ʈ�� ���̴�" << len << "�Դϴ�. \n";
				break;
			case 8:
				mylist->PrintList();
				break;
			case 9:
				mylist->DeDuplicate();
				break;
			case 10:
				listcheck = false;
				cout << "\n";
				break;
			}
		}

		break;
	}//cppchoise case 1 end
	case 2:		//������ �����ߴٸ� �Ʒ��� ǥ��
	{
		bool stackcheck = true;		//while ����
		int stacknum;		//switch ����
		int InsertstackNum;		//Push�� ����
		int stcon;		//stacklength ����
		bool stch;		//IsEmpty ����
		int repop;		//pop����
		int bgop=NULL;		//bgoperator ����
		int box;

	
		stackClass* stacklist = new stackClass();		//���� ����Ʈ ����
		stackClass::stackClass();			//���� ����Ʈ �ʱ�ȭ
		cout << "���ø���Ʈ�� �����߽��ϴ�. \n�۾��ϰ� ���� ������ �������ּ���. \n\n";
		while (stackcheck)
		{
			cout << "1.����\n";
			cout << "2.Pop\n";
			cout << "3.����ִ��� Ȯ��\n";
			cout << "4.������ ����\n";
			cout << "5.��������\n";
			cout << "6.���ú���\n";
			cout << "7 Gettop\n";
			cout << "8.������ ���ư���\n";
			cin >> stacknum;
			cout << "\n";
			switch (stacknum)
			{
			case 1:		//������ �����ߴٸ� 
			{
				cout << "������ ���� �������ּ��� \n";
				cin >> InsertstackNum;
				cout << "\n";
				stacklist->Push(InsertstackNum);
				break;
			}
			case 2:		//���� �����ߴٸ�
			{
				repop=stacklist->Pop();
			//	cout << repop << "�� pop�Ǿ����ϴ�. \n\n";
				break;
			}
			case 3:		//����ִ��� Ȯ���� �����ߴٸ�
			{
				stch = stacklist->stackIsEmpty();
				if (stch == true)
				{
					cout << "����Ʈ�� ����ֽ��ϴ�.\n\n";
				}
				else
				{
					cout << "����Ʈ�� ������� �ʽ��ϴ�.\n\n";
				}
				break;
			}
			case 4:		//������ ������ �����ߴٸ�
			{
				stacklist->stackLength();
				stcon = stacklist->stackLength();
				cout << "������ ���̴�" << stcon << "�Դϴ�. \n\n";

				break;
			}
			case 5:		//���������� �����ߴٸ�
			{
				char op[max];

				cout << "����ǥ�� ������ �Է����ּ���.\n";
				fflush(stdin);
				cin.getline(op, max); //�Է¹��� \n���ֱ�
				cin.getline(op, max);
				bgop = stacklist->bgoperator(op);
				cout << "�������� �����" << bgop << "�Դϴ�\n\n";
				break;
			}
			case 6:		//����Ʈ �ʱ�ȭ�� �����ߴٸ�
			{
				stacklist ->~stackClass();
				break;
			}
			case 7:		//Gettop�� �����ߴٸ�
			{
				int ko;
				ko=stacklist ->GetTop(box);
				cout << "���� top�� �ִ� �����ʹ� "<< ko <<"�Դϴ�. \n";
				break;
			}
			case 8:		//�������� ���ư��⸦ �����ߴٸ�
			{
				stackcheck = false;
				cout << "\n";
				break;
			}
			}
		}

		break;
	} //cppchoise case2 end
	case 3:		//���Ḧ �����ߴٸ� while���� ����
	{
		firstchoise = false;
		break;
	}
		

	} //cppchoise end

		}//firstchoise end

}// main funtion end