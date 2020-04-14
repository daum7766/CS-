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

listClass::listClass()		//생성자 함수
{
	Count = 0;				//리스트의 길이를 0으로 초기화
	Head = NULL;			// 헤드를 NULL로 초기화
}
bool listClass::IsEmpty()	// 빈 리스트인지 확인하는 함수
{
	return (Count == 0);	//배열길이가 0이면 True를 반환
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
		cout <<"현재위치에는 넣을수 없습니다.\n"; //이격된 삽입위치 불허
	else
	{
		Nptr p = (node *)malloc(sizeof(node));		//삽입될 노드의 공간 확보
		p->Data = Item;		//데이터 값 복사9
		if (Position == 1)		//첫위치에 삽입할 경우
		{
			p->Next = Head;		//삽입노드가 현재 첫 노드를 가리킴
			Head = p;		//헤드가 삽입 노드를 가리키게
		}
		else          //첫위치가 아닐경우
		{
			Nptr Temp = Head;		//헤드포인터를 Temp로 복사
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;		//Temp가 삽입직전 노드를 가리키게
			p->Next = Temp->Next;		//삽입노드의 Next를 설정
			Temp->Next = p;		//직전노드가 삽입된 노드를 가리키게
		}
		Count += 1;		//리스트 길이를 늘림
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


void listClass::Delete(int Position)		//삭제함수
{
	int *p=0;
	Nptr Temp=0;
	if (IsEmpty())
		cout << "빈리스트는 삭제할수 없습니다.";		//빈 리스트에 삭제 요구는 오류
	else if ((Position > Count) || (Position < 1))
		cout << "삭제하려는 위치가 범위를 벗어났습니다.";		//삭제위치가 데이터 범위를 벗어남
	else
	{
		if (Position == 1)						//삭제될 노드가 첫 노드일 경우
		{
			Nptr p = Head;						//삭제될 노드를 가리키는 포인터를 백업
			Head = Head->Next;					//헤드가 둘째 노드를 가리키게
		}
		else									//삭제노드가 첫 노드가 아닌 경우
		{
			Temp = Head;
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;				//Temp가 삭제될 노드인 직전 노드로 이동
			Nptr p = Temp->Next;				//삭제될 노드를 가리키는 포인터를 백업
			Temp->Next = p -> Next;				//직전노드가 삭제될 노드 다음을 가리키게
		}
		Count -= 1;								//리스트 길이를 줄임
		delete(p);								//메모리 공간 반납
	}
}

listClass::~listClass()
{
	while (!IsEmpty())							// 소멸자 함수
		Delete(1);								// 리스트가 완전히 빌 때까지
}
listClass::listClass(const listClass& L)		// 복사 생성자 함수
{
	Count = L.Count;							//일단 리스트 개수를 동일하게
	if (L.Head == NULL)
		Head = NULL;							//넘어온게 빈리스트라면 자신도 빈리스트
	else
	{
		Head = new node;						//빈 리스트가 아니라면 일단 새 노드를 만들고
		Head->Data = L.Head->Data;				//데이터 복사
		Nptr Temp1 = Head;						//Temp1은 사본을 순회하는 포인터
		for (Nptr Temp2 = L.Head->Next;
			Temp2 != NULL; Temp2 = Temp2 -> Next)
		{
			Temp1->Next = new node;				//사본의 현재 노드에 새 노드를 붙임
			Temp1 = Temp1->Next;				//새 노드로 이동
			Temp1->Data = Temp2->Data;			//새 노드에 원본 데이터를 복사
		}
		Temp1->Next = NULL;						//사본의 마지막 노드의 Next에 널을 기입
	}
}

