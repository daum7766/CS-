#pragma once
#ifndef _nodeRecord_H__
#define _nodeRecord_H__


typedef struct nodeRecord
{
	int Data;
	struct nodeRecord* Next;
}node;
typedef node* Nptr;

#endif // _nodeRecord_H__
class listClass
{
public:
	listClass();		// ����Ʈ �ʱ�ȭ
	listClass(const listClass&L);		//��������� �Լ�
	~listClass();		//�Ҹ��� �Լ�
	void Insert(int Position, int Item);		//�����Լ�
	void Delete(int position);		//���� �Լ�
	int Retrieve(int Position, int& Item);		//�˻��Լ�
	void Reverse();		//������ �Լ�
	void Random_Append(int rp, int rn);		//�����Լ� �߰�
	void PrintList();		//����Լ�
	bool IsEmpty();		//�󸮽�Ʈ Ȯ�� �Լ�
	int Length();		//���� Ȯ�� �Լ�
	void DeDuplicate();	//�ߺ���� ����

private:
	int Count;
	Nptr Head;
};
