#pragma once
#include <string>
#include<iostream>
using namespace std;
#include "ListP.h"

#ifndef _nodeRecord_H__
#define _nodeRecord_H__
typedef struct nodeRecord
{
	int Data;
	struct nodeRecord* Next;
}node;
typedef node* Nptr;
#endif // _nodeRecord_H__

class stackClass
{
public:
	stackClass();		//생성자 함수
	~stackClass();		//소멸자 함수
	void Push(int Item);		//Item 값을 스택에 삽입
	int Pop();		//스택 탑의 데이터 값을 리턴함
	bool stackIsEmpty();		//비어 있는지 확인
	int stackLength();		//스택길이 확인
	int bgoperator(char *op);		//후위연산 함수
	int GetTop(int &Item);

private:
	//int Count;
	//Nptr Top;		//첫 노드를 가리키는 포인터
	listClass L;
};
