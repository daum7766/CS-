#include <stdio.h>
#include "StackA.h"
#include <iostream>		 //cout 사용가능하게해줌
#include <string>


using namespace std;	//cout 사용가능하게 해줌

stackClass::stackClass()		//생성자 함수
{
	//Top = NULL;		//탑포인트를 NULL로 지정
	//Count = 0;		//카운트 0으로 지정(따로제작)
}

stackClass::~stackClass()		//소멸자 함수
{
	//int Temp;
	//while (!IsEmpty())		//비어있지 않다면 계속 팝한다.
	//	Temp = Pop();
}
bool stackClass::stackIsEmpty()		//비어있는지 확인
{
	//return bool(Top == NULL);		//top이 NULL인지 확인
	return bool(L.IsEmpty());

}

void stackClass::Push(int Item)		//item값을 스택에 삽입하는 함수
{
	//Nptr NewTop = new node;		//새로운 노드 생성
	//NewTop->Data = Item;		//새로운 노드 탑에 아이템을 넣음
	//NewTop->Next = Top;		//새로운 노드가 가리키는 포인터에 탑을 넣음
	//Top = NewTop;		//탑을 새로운 노드로 바꿈
	//Count++;		//카운터 증가
	L.Insert(1, Item);
}

int stackClass::Pop()		//스택 탑의 데이터값을 리턴함.
{
	int Item;
	//if (IsEmpty())		//비어있다면 삭제할수없다고 알림
	//	cout << "빈리스트는 삭제할수 없습니다.\n";
	//else
	//{
	//	Count--;		//카운터 감수
	//	Nptr Temp = Top;		//템프에 탑노드를 집어넣음
	//	int Item = Temp->Data;	//아이템에 템프의 데이터값을 집어넣음
	//	Top = Top->Next;		//탑을 탑이가리키는 포인터쪽으로 바꿈
	//	delete Temp;		//temp를 반납함.
	//	return Item;		//item값을 리턴함
	//}
	L.Delete(1);
	return 0;
}

int stackClass::stackLength()		//스택에 넣은 데이터의 갯수를 찾는 함수
{
	return L.Length();				//카운터 수를 리턴함.
}

int stackClass::bgoperator(char *op)		//후위연산 함수
{
	int i,kk;	//for 문
	int a=0, b=0, v=0, s=0, re=NULL, nu=0;		//계산해야되는 값들
	int box;
	
	cout << op << "을 계산하겠습니다.\n";
	for (i=0; op[i] != NULL; i++)		//문자열이 끝날때까지 반복
	{

		if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/')
		{								//연산자 기호를 만나면
			b = stackClass::GetTop(box);	//top에있는걸 b에 집어넣음
				stackClass::Pop();		//스택에 있는걸 팝
			a = stackClass::GetTop(box);	//top에 있는걸 a에집어넣음
				stackClass::Pop();		//스택에 있는걸 팝

			if (op[i] == '+')
			{
				v = a + b;				//연산한다.
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
			stackClass::Push(v);		//연산한 값을 스택에 다시 푸쉬

		}
		else if (op[i] == ' ')		//만약 띄어쓰기라면 아무것도 하지않는다.
		{

		}
		else
		{

			if (op[i + 1] != ' '&&op[i+1] != '.')		//다음 배열이 띄어쓰기가 아니라면
			{
				s = op[i] - '0';		//현재수를 s에 저장한다.
				nu = nu + s;		//현재수의 10배를 nu에 저장한다.
				nu = 10 * nu; //nu에 10배를 해준다.

			}
			else				//다음배열이 띄어쓰기라면
			{
				s = op[i] - '0';		//현재수를 s에 저장한다.

				if (op[i + 1] == '.')
				{

					i = i + 2;

				}

				nu = nu + s;		//nu와 s를 더하여 nu에 집어넣는다.

				stackClass::Push(nu);		//nu값을 스택에 푸쉬한다.
				nu = 0;		//nu값을 0으로 초기화한다.
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