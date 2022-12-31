#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// test case
// 입력: 5 3 / 1 3 2 3 2, 출력: 8
// 입력: 8 5 / 1 5 4 3 2 4 5 2, 출력: 25

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
	
	int n = input1[0]; //볼링공의 개수
	int m = input1[1]; //볼링공의 최대 무게

	string sInput2;
	getline(cin, sInput2);
	stringstream ss2(sInput2);
	vector<int> input2;
	int tmp2;

	while (ss2 >> tmp2)
		input2.push_back(tmp2);

//계산부

	//기준이 되는 공을 잡고
	//기준 공의 무게와 같으면 count하지 않고
	//다르면 count함

	int ball = 0;//볼링공 조합 중 기준이 될 공의 무게 값을 가짐
	int count = 0;

	for (int i=0; i < n; i++) {
		ball = input2.back(); //한 번 기준공이 된 공은
		input2.pop_back(); //중복 카운트되지 않도록 빼줘야 함
		for (auto i : input2) {
			if (i != ball) { //기준공의 무게와 다르면
				count++; //조합이 될 수 있으므로 count++
			}
		}

	}

	cout << count;
	return 0;
}