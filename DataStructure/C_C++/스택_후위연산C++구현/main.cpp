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

void main()		//메인함수
{
	int firstchoise = true;
	while (firstchoise)
	{


	int cppchoice = 0;



	cout << "1.연결리스트\n";
	cout << "2.스택\n";
	cout << "3.종료\n";
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
		cout << "리스트를 생성했습니다. \n작업하고 싶은 영역을 선택해주세요. \n\n";
		while (listcheck)
		{
			cout << "1.삽입 \n";
			cout << "2.삭제 \n";
			cout << "3.검색 \n";
			cout << "4.역순 \n";
			cout << "5.난수덧붙이기 \n";
			cout << "6.비어있나확인 \n";
			cout << "7.길이확인 \n";
			cout << "8.리스트 출력 \n";
			cout << "9.중복요소제거 \n";
			cout << "10.전으로 돌아가기 \n";
			cin >> num;
			cout << "\n";

			switch (num)
			{
			case 1:
				cout << "삽입할 위치를 선택해주세요\n";
				cin >> InsertPosition;
				cout << "삽입할 값을 선택해주세요 \n";
				cin >> InsertNum;
				cout << "\n";
				mylist->Insert(InsertPosition, InsertNum);
				break;
			case 2:
				cout << "삭제할 위치를 선택해주세요\n";
				cin >> DeletePosition;
				cout << "\n";
				mylist->Delete(DeletePosition);
				break;
			case 3:
				cout << "검색하고 싶은 위치값을 선택해주세요\n";
				cin >> searchnum;
				cout << "\n";
				box = mylist->Retrieve(searchnum, box);
				if (box == 0)
				{
					cout << searchnum << "위치에 데이터가 없습니다..\n";
				}
				else
				{
					cout << searchnum << "의 위치에 있던 값은 " << box << "입니다. \n";
				}
				break;
			case 4:
				mylist->Reverse();
				cout << "리스트를 역순으로 만들었습니다.\n";
				break;
			case 5:
				cout << "생성할 난수의 갯수를 선택해주세요.\n";
				cin >> randNum;
				cout << "생성한 난수의 삽입할 위치를 선택해주세요\n";
				cin >> randPositionNum;
				cout << "\n";
				mylist->Random_Append(randPositionNum, randNum);
				break;
			case 6:
				ch = mylist->IsEmpty();
				if (ch == true)
				{
					cout << "리스트는 비어있습니다.\n";
				}
				else
				{
					cout << "리스트는 비어있지 않습니다.\n";
				}
				break;
			case 7:
				len = mylist->Length();
				cout << "리스트의 길이는" << len << "입니다. \n";
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
	case 2:		//스택을 선택했다면 아래를 표시
	{
		bool stackcheck = true;		//while 변수
		int stacknum;		//switch 변수
		int InsertstackNum;		//Push값 변수
		int stcon;		//stacklength 변수
		bool stch;		//IsEmpty 변수
		int repop;		//pop변수
		int bgop=NULL;		//bgoperator 변수
		int box;

	
		stackClass* stacklist = new stackClass();		//스택 리스트 생성
		stackClass::stackClass();			//스택 리스트 초기화
		cout << "스택리스트를 생성했습니다. \n작업하고 싶은 영역을 선택해주세요. \n\n";
		while (stackcheck)
		{
			cout << "1.삽입\n";
			cout << "2.Pop\n";
			cout << "3.비어있는지 확인\n";
			cout << "4.스택의 갯수\n";
			cout << "5.후위연산\n";
			cout << "6.스택비우기\n";
			cout << "7 Gettop\n";
			cout << "8.전으로 돌아가기\n";
			cin >> stacknum;
			cout << "\n";
			switch (stacknum)
			{
			case 1:		//삽입을 선택했다면 
			{
				cout << "삽입할 값을 선택해주세요 \n";
				cin >> InsertstackNum;
				cout << "\n";
				stacklist->Push(InsertstackNum);
				break;
			}
			case 2:		//팝을 선택했다면
			{
				repop=stacklist->Pop();
			//	cout << repop << "가 pop되었습니다. \n\n";
				break;
			}
			case 3:		//비어있는지 확인을 선택했다면
			{
				stch = stacklist->stackIsEmpty();
				if (stch == true)
				{
					cout << "리스트는 비어있습니다.\n\n";
				}
				else
				{
					cout << "리스트는 비어있지 않습니다.\n\n";
				}
				break;
			}
			case 4:		//스택의 갯수를 선택했다면
			{
				stacklist->stackLength();
				stcon = stacklist->stackLength();
				cout << "스택의 길이는" << stcon << "입니다. \n\n";

				break;
			}
			case 5:		//후위연산을 선택했다면
			{
				char op[max];

				cout << "후위표현 수식을 입력해주세요.\n";
				fflush(stdin);
				cin.getline(op, max); //입력버퍼 \n없애기
				cin.getline(op, max);
				bgop = stacklist->bgoperator(op);
				cout << "후위연산 결과는" << bgop << "입니다\n\n";
				break;
			}
			case 6:		//리스트 초기화를 선택했다면
			{
				stacklist ->~stackClass();
				break;
			}
			case 7:		//Gettop을 선택했다면
			{
				int ko;
				ko=stacklist ->GetTop(box);
				cout << "스택 top에 있던 데이터는 "<< ko <<"입니다. \n";
				break;
			}
			case 8:		//이전으로 돌아가기를 선택했다면
			{
				stackcheck = false;
				cout << "\n";
				break;
			}
			}
		}

		break;
	} //cppchoise case2 end
	case 3:		//종료를 선택했다면 while문을 종료
	{
		firstchoise = false;
		break;
	}
		

	} //cppchoise end

		}//firstchoise end

}// main funtion end