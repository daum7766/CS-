#include<stdio.h>
#pragma once
#include <string>
#include<iostream>
#define MAXNODE 100
using namespace std;

static int acount=0;		//���� ������� �迭�� ����� ī��Ʈ�ϴ� ����

#define Max 100

class Heapclass
{
public:
	Heapclass();
	int* HeapCreate();					//1.����
	void Destroy(int *addr);					//2.�ı�
	void Add(int *addr, int Data);				//3.����
	void Remove(int *addr);					//4.����
	void MultiAdd(int *addr);			//5.���߻���
	void MultiRemove(int *addr);		//6.���߻���
	void PrintParent(int *addr, int Number);		//7.�θ����
	void PrintChild(int *addr, int Number);		//8.�ڽĳ�����
	void PrintHeap(int *addr);				//9.�� ���
	void DownHeap(int *addr, int Current);		//�ٿ� ��

private:
	int count;		//�� ����� ����
	int *addr[Max];			//�迭 �ּҸ� �������ִ� ����

};

