#include<stdio.h>
#pragma once
#include <string>
#include<iostream>
#define MAXNODE 100
using namespace std;

static int acount=0;		//현재 만들어진 배열이 몇개인지 카운트하는 변수

#define Max 100

class Heapclass
{
public:
	Heapclass();
	int* HeapCreate();					//1.생성
	void Destroy(int *addr);					//2.파기
	void Add(int *addr, int Data);				//3.삽입
	void Remove(int *addr);					//4.삭제
	void MultiAdd(int *addr);			//5.다중삽입
	void MultiRemove(int *addr);		//6.다중삭제
	void PrintParent(int *addr, int Number);		//7.부모출력
	void PrintChild(int *addr, int Number);		//8.자식노드출력
	void PrintHeap(int *addr);				//9.힙 출력
	void DownHeap(int *addr, int Current);		//다운 힙

private:
	int count;		//힙 노드의 개수
	int *addr[Max];			//배열 주소를 가지고있는 변수

};

