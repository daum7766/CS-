#include <stdio.h>		//헤더파일을 포함
#include "ListP.h"
#include <stdlib.h>
#include <SDKDDKVer.h>
#include <tchar.h>



void Init(listType *Lptr)		//초기화 함수
{
	Lptr->Count = 0;		//리스트의 길이를 0으로 초기화
	Lptr->Head = NULL;		//헤드 포인터를 NULL로 초기화
}
bool IsEmpty(listType *Lptr)		//빈 리스트인지 알아보기
{return(Lptr->Count == 0);		//리스트 길이가 0이면 빈리스트
}
void Insert(listType *Lptr, int Position, int Item)		//삽입함수
{
	if ((Position > (Lptr->Count + 1)) || (Position < 1))
		printf("현재위치에는 넣을수 없습니다.\n"); //이격된 삽입위치 불허
	else
	{
		Nptr p = (node *)malloc(sizeof(node));		//삽입될 노드의 공간 확보
		p->Data = Item;		//데이터 값 복사9
		if (Position == 1)		//첫위치에 삽입할 경우
		{
			p->Next = Lptr->Head;		//삽입노드가 현재 첫 노드를 가리킴
			Lptr->Head = p;		//헤드가 삽입 노드를 가리키게
		}
		else          //첫위치가 아닐경우
		{
			Nptr Temp = Lptr->Head;		//헤드포인터를 Temp로 복사
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;		//Temp가 삽입직전 노드를 가리키게
			p->Next = Temp->Next;		//삽입노드의 Next를 설정
			Temp->Next = p;		//직전노드가 삽입된 노드를 가리키게
		}
		Lptr->Count += 1;		//리스트 길이를 늘림
	}
}

void Delete(listType *Lptr, int Position)
{
	int* p=0;
	if (IsEmpty(Lptr))
		printf("리스트가 비어있습니다.\n");		//빈 리스트에서 삭제요구는 오류
	else if (Position > (Lptr -> Count) || (Position < 1))
		printf("데이터 범위를 벗어났습니다.\n");		//삭제위치가 현재 데이터 범위를 벗어남
	else
	{
		if (Position == 1)		//첫 노드를 삭제하는 경우
		{
			Nptr p = Lptr->Head;		//삭제될 노드를 가리키는 포인터를 백업
			Lptr->Head = Lptr->Head->Next;		//헤드가 둘째 노드를 가리키게

		}
		else
		{
			Nptr Temp = Lptr->Head;
			for (int i = 1; i < (Position - 1); i++)
				Temp = Temp->Next;		//Temp가 삭제직전 노드를 가리키게
			Nptr p = Temp->Next;		//삭제될 노드를 가리키는 포인터를 백업
			Temp->Next = p->Next;		//직전 노드가 삭제될 노드 다음 노드를 가리키게
		}
		Lptr->Count -= 1;
		free(p);
	}
}

void Reverse(listType *Lptr)		//뒤집는 함수
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
void Random_Append(listType *Lptr,int rp ,int rn)		//난수생성함수
{
	int ii;
	srand((unsigned)time(NULL));
	for (ii = 1; ii <= rn; ii++)
	{
		Insert(Lptr, rp, rand());
		rp = rp++;
	}
}

int Retrieve(listType *Lptr, int Position, int *ItemPtr)		//탐색함수
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
void PrintList(listType *Lptr)		//화면출력함수
{
	Nptr Temp = Lptr->Head;
	printf("리스트값 : ");
	while (Temp != NULL)
	{
		printf("%d ->", Temp->Data);
		Temp = Temp->Next;
	}
	printf("NULL.\n");
}

int Length(listType *Lptr)		//길이확인 함수
{
	printf("리스트의 길이는 %d 입니다.\n", Lptr->Count);
	return Lptr->Count;
}

void main()		//메인함수
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
	printf("리스트를 생성했습니다. \n작업하고 싶은 영역을 선택해주세요. \n");
	while (check)
	{
		printf("1.삽입 \n");
		printf("2.삭제 \n");
		printf("3.검색 \n");
		printf("4.역순 \n");
		printf("5.난수덧붙이기 \n");
		printf("6.비어있나확인 \n");
		printf("7.길이확인 \n");
		printf("8.리스트 출력 \n");
		printf("9.종료 \n");
		scanf_s("%d", &num);
		switch(num)
		{case 1:
			printf("삽입할 위치를 선택해주세요\n");
			scanf_s("%d", &InsertPosition);
			printf("삽입할 값을 선택해주세요 \n");
			scanf_s("%d", &InsertNum);
			printf("\n");
			Insert(mylist, InsertPosition, InsertNum);
			break;
		case 2:
			printf("삭제할 위치를 선택해주세요\n");
			scanf_s("%d", &DeletePosition);
			printf("\n");
			Delete(mylist, DeletePosition);
			break;
		case 3:
			printf("검색하고 싶은 위치값을 선택해주세요\n");
			scanf_s("%d", &searchnum);
			printf("\n");
			box=Retrieve(mylist, searchnum, box);
			if (box == 0)
			{
				printf("%d 위치에 데이터가 없습니다..\n", searchnum);
			}
			else
			{
				printf("%d의 위치에 있던 값은 %d 입니다. \n", searchnum, box);
			}
			break;
		case 4:
			Reverse(mylist);
			printf("리스트를 역순으로 만들었습니다.\n");
			break;
		case 5:
			printf("생성할 난수의 갯수를 선택해주세요.\n");
			scanf_s("%d", &randNum);
			printf("생성한 난수의 삽입할 위치를 선택해주세요\n");
			scanf_s("%d", &randPositionNum);
			printf("\n");
			Random_Append(mylist, randPositionNum ,randNum);
			break;
		case 6:
			ch=IsEmpty(mylist);
			if (ch == true)
			{
				printf("리스트는 비어있습니다.\n");
			}
			else
			{
				printf("리스트는 비어있지 않습니다.\n");
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