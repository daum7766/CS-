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
	listClass();		// 리스트 초기화
	listClass(const listClass&L);		//복사생성자 함수
	~listClass();		//소멸자 함수
	void Insert(int Position, int Item);		//삽입함수
	void Delete(int position);		//삭제 함수
	int Retrieve(int Position, int& Item);		//검색함수
	void Reverse();		//뒤집기 함수
	void Random_Append(int rp, int rn);		//랜덤함수 추가
	void PrintList();		//출력함수
	bool IsEmpty();		//빈리스트 확인 함수
	int Length();		//길이 확인 함수
	void DeDuplicate();	//중복요소 삭제

private:
	int Count;
	Nptr Head;
};
