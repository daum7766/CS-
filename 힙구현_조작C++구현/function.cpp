#include <stdio.h>
#include <iostream>		 //cout 사용가능하게해줌
#include "head.h"
#include <string>
#define Max 100

using namespace std;	//cout 사용가능하게 해줌


Heapclass::Heapclass()		//생성자 함수
{
	count = 0;			
}
int* Heapclass::HeapCreate()						//1.생성
{

	int *addr = new int[Max];
	cout << "배열을 생성했습니다. \n";
	cout << "배열의 최대크기는 100입니다.\n";
	return addr;

}

void Heapclass::Destroy(int *addr )					//2.파기
{

		delete addr;
		count = 0;

}
void Heapclass::Add(int *addr,int Data)				//3.삽입
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
void Heapclass::Remove(int *addr)						//4.삭제
{
		int ret = *addr;
		*(addr) = *(addr + (count - 1));
		count--;
		cout << ret << "를 삭제했습니다.\n";
		DownHeap(addr, 0);

}
void Heapclass::MultiAdd(int *addr)			//5.다중삽입
{
		int in = 0;		//입력할 데이터 개수
		int data = 0;	//입력받는 데이터
		cout << "몇개의 데이터를 삽입할지 입력해주세요\n";
		cin >> in;
		if (in <= Max - count)
		{
			for (int i = 0; i < in; i++)
			{
				cout << i + 1 << "번째 데이터를 입력해주세요\n";
				cin >> data;
				Add(addr, data);
			}
			cout << "모든 데이터를 입력했습니다.\n";
		}
		else
		{
			cout << "최대갯수를 초과했습니다.\n";
		}


}
void Heapclass::MultiRemove(int *addr)	//6.다중삭제
{
		int Number;
		cout << "삭제할 노드의 개수를 입력해주세요\n";
		cin >> Number;
		if (Number <= count)
		{
			for (int i = 0; i < Number; i++)
			{
				Remove(addr);
			}

		}
		else {
			cout << "입력한 값이 총노드의 개수보다 많습니다.";
		}
}
void Heapclass::PrintParent(int *addr, int Number)	//7.부모출력
{


		int Parent;
		if (Number == 0)
		{
			cout << "부모노드가 없습니다.\n";
		}
		else if (Number > count - 1)
		{
			cout << "현재노드는 데이터가 없습니다\n";
		}
		else
		{
			Parent = (Number - 1) / 2;
			cout << *(addr + Parent) << "(" << Parent << ")" << "->" << *(addr + Number) << "(" << Number << ")";
		}
}
void Heapclass::PrintChild(int *addr, int Number)		//8.자식노드출력
{

		if (Number > count - 1)
		{
			cout << "현재 선택한 노드에는 데이터가 없습니다.\n";
		}
		else
		{

			int LChild;
			int RChild;
			LChild = (Number * 2) + 1;
			RChild = LChild + 1;
			if (LChild > count - 1)
			{
				cout << "현재노드의 자식노드는 없습니다\n";
			}
			else if (RChild > count - 1)
			{
				cout << *(addr + LChild) << "(" << LChild << ")" << "<-" << *(addr + Number) << "(" << Number << ")" << "->" << "RChild 없음";
			}
			else
			{
				cout << *(addr + LChild) << "(" << LChild << ")" << "<-" << *(addr + Number) << "(" << Number << ")" << "->" << *(addr + RChild) << "(" << RChild << ")";
			}
		}

}
void Heapclass::PrintHeap(int *addr)					//9.힙 출력
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			cout << *(addr + i) << "(" << i << "번 노드" << ") ";
		}
		cout << "\n노드의 개수는" << count << "개입니다.\n";
	}
	else
	{
		cout << "배열에 데이터가 없습니다.";
	}

}

void Heapclass::DownHeap(int *addr, int Current)	//다운 힙
{
	int LChild = (Current * 2) + 1; ;
	int RChild = LChild + 1;
	int dat;
	if (RChild >count)
	{
		if (LChild > count)
		{
			//마지막 리프까지왔음
		}
		else		//LChild가 count보다 적거나 같으면
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