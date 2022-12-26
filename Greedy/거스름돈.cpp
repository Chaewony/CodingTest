#include <iostream>
using namespace std;

int main()
{
	int change, num = 0;
	cin >> change;

	//나머지 계산 시 몫 계산에 사용되는 change 값을 변경하므로 몫 계산을 먼저 해준다
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