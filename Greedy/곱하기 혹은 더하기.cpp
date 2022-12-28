#include <iostream>
#include <vector>

using namespace std;

// test case
// 입력: 02984, 출력: 576
// 입력: 567, 출력: 210
// 입력: 000567, 출력: 210
// 입력: 010101, 출력: 3

int main()
{
	string s;
	cin >> s;

	vector<int> vec;

	//string으로 받은 입력을 vector에 int형으로 저장
	for (int i = 0; i < s.size(); i++) {
		vec.push_back(s[i] - '0'); //0의 아스키코드 값을 빼서 s[i]을 char형에서 int으로 바꿀 수 있음
		                           //예를 들어, '3'은 아스키 코드 값으로 51, '0'은 48이므로 3이라는 값을 도출할 수 있음
	}

	int result = 0;

	//1. 현재 result가 0일 때 i를 곱하면 0이 되므로 패스
	//2. i가 0일 때 곱하면 0이 됨. 따라서 더해야 하는데 결과 값에 아무런 영향을 미치지 않으므로 패스
	//3. i가 1일 때 곱하면 그대로임. 따라더 더해야 함
	//4. 그 외 곱하는 것이 최적의 해를 보장함.

	for (auto i : vec) {
		if (result == 0) {
			result += i;
			continue; //현재 반복문을 건너뜀
		}

		if (i == 0)
			continue;
		else if (i == 1)
			result += i;
		else
			result *= i;
	}

	cout << result;
}