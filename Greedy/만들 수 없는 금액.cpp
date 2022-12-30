#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

// test case
// 입력: 3 / 3 5 7, 출력: 1
// 입력: 6 / 1 1 1 1 2 10, 출력: 7
// 입력: 6 / 1 1 1 1 2 7, 출력: 14
// 입력: 6 / 1 1 1 2 3 100, 출력: 9
// 입력: 4 / 1 2 3 5, 출력: 12

int main()
{
	//입력부
	string sInput1;
	getline(cin, sInput1);
	stringstream ss(sInput1);
	vector<int> input1;
	int tmp;
	while (ss >> tmp)
		input1.push_back(tmp);

	//n: 총 숫자의 개수를 저장할 변수
	int n = input1[0];

	string sInput2;
	getline(cin, sInput2);
	stringstream ss2(sInput2);
	vector<int> input2;
	int tmp2;

	while (ss2 >> tmp2)
		input2.push_back(tmp2);

	//오름차순 정렬
	sort(input2.begin(), input2.end());

	//numOf1: 입력 받은 수 중 1의 개수를 저장할 변수
	int numOf1 = 0;

	//1의 개수 계산
	for (auto i : input2) {
		if (i == 1) 
			numOf1++;
	}

	//1의 개수가 0이면 만들 수 없는 양의 정수 중 최솟값은 1이므로 0을 반환하며 종료한다
	if (numOf1 == 0) {
		cout << 1;
		return 0;
	}
	
	//k번째 숫자와 k+1번째 숫자의 차가 (1의 개수 +1)보다 크면
	//0번째 숫자부터 k번째 숫자의 덧셈 조합으로 다음 숫자를 만들 수 없으므로
	//0번째 숫자에서 k번째 숫자의 총합 +1 이 답임
	for (int i = 0; i < n - 1; i++) {
		if (input2[i + 1] - input2[i] > numOf1 + 1) {
			cout << accumulate(input2.begin(), input2.begin() + i + 1, 0) + 1;
			return 0;
		}
	}

	//k=n일 경우 k+1인 n+1의 값이 null이므로 따로 빼서 정의해줌
	//위에서 수행한 것과 논리는 같음 
	
	//n-1번째 숫자들로 n을 만들 수 있으면
	//0번째 숫자에서 n번째 숫자의 총합 +1 이 답임
	//위에서 수행한 것과 논리는 같으나 
	cout << accumulate(input2.begin(), input2.end(), 0) + 1;
	return 0;
}