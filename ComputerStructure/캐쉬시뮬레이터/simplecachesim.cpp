#include<stdio.h>
#include <iostream>		 //cout ��밡���ϰ�����
#include <string>
#include <fstream>
#include <stdlib.h>
#include <bitset>

using namespace std;	//cout ��밡���ϰ� ����

typedef struct set_Associative
{
	string Tag;
	string Data = { '\0' };
	bool v = NULL;
	int LRU = 0;
};

void pirnt()
{
	cout << "�ٽ� ��������ֽñ� �ٶ��ϴ�.";
}

void main(int argc, char *argv[])
{
	bool end = true;		//�ݺ��� ���ἱ��
	ifstream file;		//���� ������ ���� ����
	char str[sizeof(file)] = { '\0' };
	int access=0;
	float hit_count=0;
	float hit_rate=0;
	int tag=0;
	int index=0;
	int offset=0;
	string Memory_Trace;	//�޸� Ʈ���̽����� �̸�
	int Cache_Byte;		//ĳ�� ��ü ����Ʈ ���� ũ��
	int Cache_Block_Byte;		//ĳ�� ��� ����Ʈ ũ��
	int Associativity;		//associativity ���ϱ�


	if (argc != 5)
	{
		cout << "�μ��� ������ �߸�����ϴ�.\n";
		pirnt();
	}


	Memory_Trace = argv[1];
	Cache_Byte = atoi(argv[2]);
	Cache_Block_Byte = atoi(argv[3]);
	Associativity = atoi(argv[4]);
	set_Associative** sa;

	sa = new set_Associative*[Associativity];
	for (int i = 0; i < Associativity; i++)
	{
		sa[i] = new set_Associative[Cache_Byte / Cache_Block_Byte];
	}

		file.open(Memory_Trace);		//file open
		if (file.good())
		{
			if (Cache_Byte < 1)
			{
				cout << "Cache_Byte�� �߸��Է��ϼ̽��ϴ�.\n";
				pirnt();
			}
			if (Cache_Block_Byte % 2 != 0)
			{
				cout << "\nCache Block�� ũ�Ⱑ 2��  �������� �ƴմϴ�.\n";

				pirnt();
			}
			if (Cache_Block_Byte > Cache_Byte)
			{
				cout << "\n ��ϻ���� ��ü ������� Ů�ϴ�.";
				pirnt();
			}
			if (Associativity != 1 && Associativity != 2 && Associativity != 4 && Associativity != 8)
			{
				cout << "N ���� 1,2,4,8�߿��� �������� �ʾҽ��ϴ�.\n";
				pirnt();
			}
			if (Cache_Byte % Cache_Block_Byte * Associativity != 0)
			{
				cout << "Cache ��ü�� ũ�Ⱑ (cache block ũ��)x(associativity)�� ����� �ƴմϴ�.\n";
				pirnt();
			}

			offset = log2(Cache_Block_Byte);
			index = log2(Cache_Byte / Cache_Block_Byte / Associativity);
			tag = 32 - offset - index;
			while (!file.eof())
			{
				int a;
				char st[9] = { '\0' };
				char bc[10] = { '\0' };
				char tc[33] = { '\0' };
				char oc[33] = { '\0' };
				access = access + 1;

				file.getline(str, sizeof(file));
				for (int i = 0; i < 8; i++)
				{
					st[i] = str[4 + i];
				}
				a = strtol(st, NULL, 16);
				string at = bitset<32>(a).to_string();
				for (int i = 0; i < index; i++)
				{
					bc[i] = at[tag+i];
				}
				for (int i = 0; i < tag; i++)
				{
					tc[i] = at[i];
				}
				for (int i = 0; i < offset; i++)
				{
					oc[i] = at[tag+index-1+i];
				}
				int abc;
				int N;
				int mini;
				abc = atoi(bc);
				N=abc%Associativity;
				int minLRU = 999999;
				for (int i = 0; i < (Cache_Byte / Cache_Block_Byte); i++)
				{
					if (sa[N][i].v == NULL)
					{
						sa[N][i].v = true;
						sa[N][i].LRU = access;
						sa[N][i].Tag = tc;
						sa[N][i].Data = oc;
						break;
					}
					else if (sa[N][i].v == true)
					{
						if (sa[N][i].Tag == tc)
						{
							if (sa[N][i].Data == oc)
							{
								hit_count++;
								break;
							}
							else if (sa[N][i].Data != oc)
							{
								if (minLRU >= sa[N][i].LRU)
								{
									minLRU = sa[N][i].LRU;
									mini = i;
								}
							}
						}
						else if (sa[N][i].Tag != tc)
						{
							if (minLRU >= sa[N][i].LRU)
							{
								minLRU = sa[N][i].LRU;
								mini = i;
							}
						}
						if (i== (Cache_Byte / Cache_Block_Byte)-1)
						{
							sa[N][mini].LRU = access;
							sa[N][mini].Tag = tc;
							sa[N][mini].Data = oc;
							break;
						}
					}

				}
				

			}
			cout << "tag : "<< tag <<"bits\n";
			cout << "index : "<< index <<"bits\n";
			cout << "offset : "<< offset <<"bits\n";
			hit_rate = hit_count / access;
			cout << "Result : total access "<< access <<", hit "<< hit_count  <<", hit rate " << hit_rate <<"\n";
		}
		else
		{
			cout << "\n������ �������� ���߽��ϴ�.\n";
			pirnt();
		}
		file.close();		//������ ���� ����
		getchar();
	


}