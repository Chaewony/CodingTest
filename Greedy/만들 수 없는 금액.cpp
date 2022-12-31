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
// 입력: 7 / 1 1 1 1 5 8 13, 출력: 31
// 입력: 7 / 1 1 1 1 5 8 14, 출력: 32
// 입력: 5 / 1 3 4 5 6, 출력: 2

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

	//계산부
		//오름차순 정렬
	sort(input2.begin(), input2.end());

	//입력받은 숫자 중 가장 작은 수가 1이 아니면
	//만들 수 없는 양의 정수 중 최솟값은 1이므로 1을 출력하고 종료
	if (input2[0] != 1) {
		cout << 1;
		return 0;
	}

	//0번 부터 i-1번째 까지의 숫자들의 조합으로 i번째 숫자를 만들 수 없으면
	//0번째 숫자에서 최대 i-1번째 숫자 까지의 총합까지 연속된 숫자를 만들 수 있고
	//그 이상의 수는 만들 수 없으므로 0번째 숫자에서 i-1번째 숫자의 총합 +1 이 답임

	//i번째 숫자에서 0부터 i-1번째 숫자들의 합을 뺐을 때 1보다 크면
	//0부터 i번째 숫자들로 0부터 i번째 숫자들의 합까지의 연속된 숫자를 만들 수 없음
	for (int i = 1; i < input2.size(); i++) {
		tmp = input2[i];
		for (int j = i - 1; j >= 0; j--) {
			tmp = tmp - input2[j];
		}
		if (tmp > 1) { //0부터 i-1번째 숫자들의 합 + 1
			cout << accumulate(input2.begin(), input2.begin() + i, 0) + 1;
			return 0;
		}
	}

	//i=n(끝,마지막)일 경우 i+1인 n+1의 값이 null이므로 따로 빼서 계산해줌
	//위에서 수행한 것과 논리는 같음 

	//0부터 n-1번째 숫자들로 n번째 숫자를 만들 수 있으면
	//n까지의 총합 까지의 연속된 숫자를 만들 수 있음
	//따라서 만들 수 없는 최솟값은 0번째 숫자(처음)에서 n번째 숫자(끝)의 총합 +1 임
	cout << accumulate(input2.begin(), input2.end(), 0) + 1;
	return 0;
}