#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	//공백문자로 구분하여 입력받기
	string string1;
	getline(cin, string1);
	stringstream stringStream1(string1);
	vector<int> firstInput;
	int tmpNumber1;

	while (stringStream1 >> tmpNumber1)
		firstInput.push_back(tmpNumber1);

	//문제에서 주어진 n값
	int n  = firstInput[0];
	//문제에서 주어진 k값
	int k = firstInput[1];

	int count = 0;
	
	//n이 k의 배수가 될 때까지 n에서 1을 뺌
	while (n % k != 0) {
		n -= 1;
		count++;
	}

	//n이 1이 될 때까지 k로 나눔
	while (n != 1) {
		n /= k;
		count++;
	}

	cout << count;
}