#include <iostream>
#include <vector>

using namespace std;

// test case
// 입력: 0001100, 출력: 1
// 입력: 010100, 출력: 2
// 입력: 11110100, 출력: 2

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

	//연속된 숫자를 뒤집어서 전부 같은 숫자로 만들기 위한 최소 횟수를 구함
	//입력 값에서 0숫자들의 묶음 수와 1숫자들의 묶음 수 중 최소 갯수와 같다

	int tmp = -1; // 가장 최근에 flip한 대상의 값을 저장할 변수, 이 값과 비교하여 같으면 같은 숫자 묶음에 포함 되는 것으로 간주
	int count0 = 0; // 0 숫자 묶음의 수
	int count1 = 0; //1 숫자 묶음의 수

	for (auto i : vec) {
		//비교 대상이(이하 i) tmp와 같을 경우: 같은 숫자 뭉치에 포함 되는것으로 간주하고 다음 반복문으로 넘어감
		if (i == tmp)
			continue;
		//i와 tmp가 다르고 i가 0일 경우: 0숫자 뭉치의 시작이므로 count0 증가
		if (i == 0)
			count0++;
		//i와 tmp가 다르고 i가 1일 경우: 1숫자 뭉치의 시작이므로 count1 증가
		else
			count1++;
		//숫자 뭉치가 i숫자 뭉치로 변경되었으므로 tmp 값을 i로 변경
		tmp = i;
	}

	//0과 1숫자 뭉치 갯수 중 최솟값을 출력
	int result = min(count0, count1);
	cout << result;
}