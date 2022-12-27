#include <iostream>
#include <vector>
#include <algorithm>
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

	//행의 갯수
	int n = firstInput[0];
	//열의 갯수
	int m = firstInput[1];

	//각 행의 최소 값을 저장할 벡터
	vector<int> mins;

	//n행만큼 입력받기
	for (int i = 0; i < n; i++)
	{
		//공백문자로 구분하여 입력받기
		string string2;
		getline(cin, string2);
		stringstream stringStream2(string2);
		vector<int> secondInput;
		int tmpNumber2;
		while (stringStream2 >> tmpNumber2)
			secondInput.push_back(tmpNumber2);
		
		//i행의 최소값을 mins에 저장
		int min = *min_element(secondInput.begin(), secondInput.end());
		mins.push_back(min);
	}

	//mins에 저장된 값 중 가장 큰 값을 출력
	int max = *max_element(mins.begin(), mins.end());
	cout << max;
}