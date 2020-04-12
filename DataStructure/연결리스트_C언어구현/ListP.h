#define _CRT_SECURE_NO_WARNINGS

typedef struct nodeRecord
{
	int Data;		//��� ������ ���� ������ �Ǵ� ���ڵ�
	struct nodeRecord* Next ;	//Next�� ����Ű�� ���� node Ÿ��, �� �ڱ� �ڽ� Ÿ��
} node;		//����ü�� node ��� ���ο� Ÿ�Ը� �ο�

typedef node* Nptr;		//Nptr Ÿ���� ����Ű�� ���� node Ÿ��


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
void Insert(listType *Lptr, int Position, int Item);		// ������ ����
void Delete(listType *Lptr, int Position);		// ������ ����
int Retrieve(listType *Lptr, int Position, int *ItemPtr);		// ã�� �����͸� *ItemPtr�� ����
void Reverse(listType *Lptr);		//����
void Random_Append(listType *Lptr);		//�����Լ� �߰�
void Init(listType *Lptr);		//�ʱ�ȭ
bool IsEmpty(listType *Lptr);		//����ִ��� Ȯ��
int Length(listType *Lptr);		//����Ʈ �� ������ ����
void PrintList(listType *Lptr);		//����Լ�
