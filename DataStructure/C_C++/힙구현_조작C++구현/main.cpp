#include <stdio.h>
#include <iostream>		 //cout 사용가능하게해줌
#include "head.h"
#include <string>
#define Max 100

using namespace std;	//cout 사용가능하게 해줌


void main()
{
	bool end = true;		//전체프로그램 종료변수
	int *addr[Max];			//배열 주소를 가지고있는 변수
	Heapclass *myHeap = new Heapclass;		//클래스 생성
	Heapclass::Heapclass();					//클래스 초기화
	while (end)				//전체 프로그램 반복
	{

		int num = false;		//스위치 변수
		int bcount = 0;			//배열 카운터(힙에 몇개가 들어있는지)

		string list[] = { "생성", "파기", "삽입", "삭제", "다중 삽입", "다중 삭제", "부모 출력", "자식출력", "힙출력","종료" };
		cout << "\n******** 메뉴 ********\n";
		for (int i = 1; i <= 10; i++)
		{
			cout << i << "." << list[i - 1] << "\n";
		}		// for문 종료
		cout << "\n메뉴를 선택해 주세요.\n";
		cin >> num;

		switch (num)
		{
		case 1:		//생성
			if (acount == 0)
			{
				addr[acount] = myHeap->HeapCreate();
				acount++;
			}
			else
			{
				cout << "배열은 이미 생성되었습니다.";
			}
			break;
		case 2:		//파기
			if (acount == 0)
			{
				cout << "삭제할 배열이 없습니다.\n";
			}
			else if (acount == 1)
			{
				myHeap->Destroy(addr[acount-1]);
				cout << "배열을 삭제했습니다.\n";
				acount--;
			}

			break;
		case 3:		//삽입
			int ad;		//삽입할 데이터 변수
			if (acount == 0)
			{
				cout << "삽입할 배열이 없습니다.";
			}
			else
			{
				cout << "삽입할 값을 입력해주세요\n";
				cin >> ad;
				myHeap->Add(addr[acount - 1], ad);
				cout << "데이터를 입력했습니다.\n";
			}
			break;
		case 4:		//삭제
			if (acount == 0)
			{
				cout << "삭제할 배열이 없습니다.";
			}
			else
			{
				myHeap->Remove(addr[acount - 1]);
			}
			break;
		case 5:		//다중 삽입
			if (acount == 0)
			{
				cout << "삽입할 배열이 없습니다.";
			}
			else
			{
				myHeap->MultiAdd(addr[acount - 1]);

			}
			break;
		case 6:		//다중삭제
			if (acount == 0)
			{
				cout << "삭제할 배열이 없습니다.";
			}
			else
			{
				myHeap->MultiRemove(addr[acount - 1]);
			}
			break;
		case 7:		//부모 출력
			if (acount == 0)
			{
				cout << "출력할 배열이 없습니다.";
			}
			else
			{
				int paprint;		//몇번째의 부모를 출력할지 정하는 변수
				cout << "몇번째 노드의 부모노드를 출력할지 입력해주세요\n";
				cin >> paprint;
				myHeap->PrintParent(addr[acount - 1], paprint);
			}
			break;
		case 8:		//자식 출력
			if (acount == 0)
			{
				cout << "출력할 배열이 없습니다.";
			}
			else
			{
				int child;		//몇번째 노드의 자식노드를 출력할지 정하는 변수
				cout << "몇번째 노드의 자식노드를 출력할지 입력해주세요\n";
				cin >> child;
				myHeap->PrintChild(addr[acount - 1], child);
			}
			break;
		case 9:		//힙 출력
			if (acount == 0)
			{
				cout << "출력할 배열이 없습니다.";
			}
			else
			{
				myHeap->PrintHeap(addr[acount - 1]);
			}
			break;
		case 10:		//종료
			end = false;
			break;

		}		// 스위치문 종료
	}		//while 종료
}		// 메인함수 종료

