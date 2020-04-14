#define _CRT_SECURE_NO_WARNINGS

typedef struct nodeRecord
{
	int Data;		//노드 내부의 실제 데이터 또는 레코드
	struct nodeRecord* Next ;	//Next가 가리키는 것은 node 타입, 즉 자기 자신 타입
} node;		//구조체에 node 라는 새로운 타입명 부여

typedef node* Nptr;		//Nptr 타입이 가리키는 것은 node 타입


typedef enum {
	true = 1,
	TRUE = 1,
	false = 0,
	FALSE = 0
} bool;

typedef struct
{
	int Count;
	Nptr Head;
} listType;
void Insert(listType *Lptr, int Position, int Item);		// 데이터 삽입
void Delete(listType *Lptr, int Position);		// 데이터 삭제
int Retrieve(listType *Lptr, int Position, int *ItemPtr);		// 찾는 데이터를 *ItemPtr에 넣음
void Reverse(listType *Lptr);		//역순
void Random_Append(listType *Lptr);		//랜덤함수 추가
void Init(listType *Lptr);		//초기화
bool IsEmpty(listType *Lptr);		//비어있는지 확인
int Length(listType *Lptr);		//리스트 내 데이터 개수
void PrintList(listType *Lptr);		//출력함수
