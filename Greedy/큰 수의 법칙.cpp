#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int makeBiggestNumber(vector<int> vec, int n, int m, int k)
{
	sort(vec.rbegin(), vec.rend()); //내림차순으로 정렬, 이유: 가장 큰 숫자와 두번째로 큰 숫자의 값이 필요하므로(가장 큰 숫자와 두번째로 큰 숫자가 같아도 됨)
	return vec[0] * k * (m / k) + vec[1] * (m % k);
}

int main()
{
	//첫번째 인풋 값을 string 자료형으로 받음
	string string1;
	getline(cin, string1);
	
	//string 자료형인 첫번째 인풋 값을 stringstream 자료형에 저장
	stringstream stringStream1(string1);

	//첫번째 줄 입력의 값을 구분하여 저장할 vector<int> 컨테이너
	vector<int> firstInput;

	//stringstream을 vector<int>에 저장하기 위해 임시로 값을 저장할 변수
	int tmpNumber1;

	//stringstream을 tmpNumber1에 저장하고
	//tmpNumber1의 값을 firstInput의 요소로 추가
	while (stringStream1 >> tmpNumber1)
		firstInput.push_back(tmpNumber1);

	int n = firstInput[0];
	int m = firstInput[1];
	int k = firstInput[2];

	//두번째 인풋
	string string2;
	getline(cin, string2);

	stringstream stringStream2(string2);

	vector<int> secondInput;

	int tmpNumber2;

	while (stringStream2 >> tmpNumber2)
		secondInput.push_back(tmpNumber2);

	cout << makeBiggestNumber(secondInput, n, m, k);
}