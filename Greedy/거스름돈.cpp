#include <iostream>
using namespace std;

int main()
{
	int change, num = 0;
	cin >> change;

	//������ ��� �� �� ��꿡 ���Ǵ� change ���� �����ϹǷ� �� ����� ���� ���ش�
	num += change / 500; 
	change %= 500;

	num += change / 100;
	change %= 100;

	num += change / 50;
	change %= 50;

	num += change / 10;
	change %= 10;

	cout << num << endl;
}