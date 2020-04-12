#include <iostream>
#include <list>
using namespace std;
void Binary(list<int> &arr, int n);
void Input(list<int> &arr1, int n, int checkNum);
int main()
{
	int n{ 0 };
	list<int> arr1, arr2 ,arr3;
	list<int>::iterator a,b;
	int checkNum{ 0 };
	do{
		cout << "n�� �Է��ϼ���" << endl;
		cin >> n;
	} while (!(n >= 1 && n <= 16));
	checkNum = pow(2, n)-1;
	cout << "ù��° �迭�� �Է��ϼ���"<<endl;
	Input(arr1, n, checkNum);
	cout << "�ι�° �迭�� �Է��ϼ���"<<endl;
	Input(arr2, n, checkNum);
	for (a= arr1.begin(), b= arr2.begin(); a != arr1.end() && b != arr2.end(); a++, b++)
		arr3.push_back(*a | *b);
	Binary(arr3, n);
	return 0;
}
void Binary(list<int> &arr, int n)
{
	list<int> temp;
	list<int>::iterator ari;
	cout << "[";
	for (ari = arr.begin(); ari != arr.end(); ari++){
		int k = *ari;
		while (true){
			temp.push_front(k % 2);
			if (k / 2 == 0)
			{
				if (temp.size() < n)
					temp.push_front(0);
				break;
			}
			k = k / 2;}
		list<int>::iterator a;
		cout << '"';
		for (a = temp.begin(); a != temp.end(); a++)
			*a == 1 ? cout << "1" : cout << "0";
		cout << '"' << ",";
		temp.clear();}
	cout << "\b]";
}
void Input(list<int> &arr1, int n ,int checkNum)
{
	do{
		int b;
		cin >> b;
		if (cin.fail()){//�Է��� �����ϸ�
			arr1.clear();
			arr1.resize(0);
			cout << "�迭�� �ٽ��Է����ּ���" << endl;
			cin.clear();
			cin.ignore(1000, '\n');}
		else if (b >= 0 && b <= checkNum)//�Է��� ���� 0���� ũ�ų� ���� n��Ʈ��ŭ ǥ���Ҽ��ִ� �ִ��������
			arr1.push_back(b);
		else{
			arr1.clear();
			arr1.resize(0);
			cout << "�迭�� �ٽ��Է����ּ���" << endl;
			cin.clear();
			cin.ignore(1000, '\n');}
	} while (arr1.size() < n);
}