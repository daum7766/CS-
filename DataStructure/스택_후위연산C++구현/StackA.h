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
	stackClass();		//������ �Լ�
	~stackClass();		//�Ҹ��� �Լ�
	void Push(int Item);		//Item ���� ���ÿ� ����
	int Pop();		//���� ž�� ������ ���� ������
	bool stackIsEmpty();		//��� �ִ��� Ȯ��
	int stackLength();		//���ñ��� Ȯ��
	int bgoperator(char *op);		//�������� �Լ�
	int GetTop(int &Item);

private:
	//int Count;
	//Nptr Top;		//ù ��带 ����Ű�� ������
	listClass L;
};
