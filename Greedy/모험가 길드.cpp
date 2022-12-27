#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//이 로직이 틀렸는지 알 수 없음
//일단 아래 케이스들은 모두 통과 됨
//case1: n=5, {2,3,1,2,2} => 2
//case2: n=7, {3,3,3,2,2,1,1} => 4
//case3: n=5, {2,3,1,2,2} => 2

// 내 코드의 로직:
// 정렬 후 가장 큰 수를 기준으로 그루핑함(내림차순)

// 정답 코드의 로직
// 정렬 후 가장 작은 수를 기준으로 비교
// 현재 그룹에 포함된 모험가의 수가 현재 확인하고 있는 공포도보다 크거나 같으면 그루핑
int main()
{
//입력부
	//첫 번째 인풋 값을 왜 주는 건지 모르겠음
	string s;
	getline(cin, s);
	stringstream ss(s);
	vector<int> vec;
	int tmp;
	while (ss >> tmp)
		vec.push_back(tmp);

	//공백문자로 구분하여 입력받기
	string string1;
	getline(cin, string1);
	stringstream stringStream1(string1);
	vector<int> input;
	int tmpNumber1;

	while (stringStream1 >> tmpNumber1)
		input.push_back(tmpNumber1);

//연산부
	//벡터를 오름차순으로 정렬
	sort(input.begin(), input.end());

	//그룹의 수를 저장할 변수
	int count = 0;

	//기준이 될 공포도 보다 남아있는 모험가가 많을 경우
	while (input.size() >= input.back()) {
		int num = input.back(); //그룹에서 가장 큰 공포도, 그룹 생성 시 기준이 되는 수, 이거 설정 안해서 틀렸었음
								//예를 들면 아래 코드에서 num 대신 input.pop_back()를 썼었는데, input.pop_back()는 아래 연산에서 수가 바뀌므로 바뀌지 않는 변수로 값을 복사해야 함
		for (int i = 0; i < num; i++) {
			input.pop_back(); 
			//input이 null이 된 후 for문의 반복 조건을 확인할 때 input.back()이 없는 벡터를 가리키므로 오류가 남
			//그래서 아래 탈출 조건을 적음
			if (input.empty())
				break;
		}
		count++;
		//input이 null이 된 후 for문의 반복 조건을 확인할 때 input.back()이 없는 벡터를 가리키므로 오류가 남
		//그래서 아래 탈출 조건을 적음
		if (input.empty())
			break;
	}

	cout << count;
}