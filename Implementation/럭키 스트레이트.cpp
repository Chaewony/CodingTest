#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main()
{
	//입력 받은 숫자가 몇 자릿수 인지 파악하기 위해 
	//string의 size() 매소드를 활용하고자 함
	//따라서 input을 int가 아닌 sting으로 받음
	string str;
	cin >> str;

	int k = str.size(); //자릿수

	//vector에 숫자들을 각각 따로 저장
	vector<int> v; 
	for (int i = 0; i < k; i++) {
		v.push_back(str[i] - '0'); //char을 int로 바꾸는 과정
	}

	//0~(자릿수/2)-1 까지의 숫자들의 합과 (자릿수)/2~끝 까지의 숫자들의 합이 같은지 비교
	//참이면 "LUCKY" 거짓이면 "READY"
	string result = accumulate(v.begin(), v.begin() + k / 2, 0) == accumulate(v.begin() + k / 2, v.end(), 0) ? "LUCKY" : "READY";
	cout << result;

	return 0;
}