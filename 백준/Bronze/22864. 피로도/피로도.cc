#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string string1;
	getline(cin, string1);
	stringstream stringStream1(string1);
	vector<int> firstInput;
	int tmpNumber1;

	while (stringStream1 >> tmpNumber1)
		firstInput.push_back(tmpNumber1);

	int A = firstInput[0]; //1시간 당 피로도 증가 폭
	int B = firstInput[1]; //1시간 당 처리할 수 있는 일
	int C = firstInput[2]; //1시간 당 피로도 감소 폭
	int M = firstInput[3]; //최대 피로도

	int work = 0;
	int fatigue = 0;

	for (int i = 0; i < 24; i++) {
		if (fatigue > M)
			break;
		if (fatigue + A > M) {
			fatigue = fatigue - C;
			if (fatigue < 0)
				fatigue = 0;
		}
		else {
			fatigue = fatigue + A;
			work = work + B;
		}
	}
	cout << work;
}