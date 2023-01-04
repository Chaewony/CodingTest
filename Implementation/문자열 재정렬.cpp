#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	////오름차순 정렬
	//sort(str.begin(), str.end());
	//cout << str << endl;
	//int sum = 0;
	//int index = 0; //제거할 문자의 개수

	////숫자와 문자 구분
	//for (auto i : str) {
	//	if (i >= '0' && i <= '9') {
	//		sum += i - '0'; //숫자면 총합에 더함
	//	}
	//	else
	//		break;
	//	index++;
	//}

	////오름차순으로 정렬된 상태에서는 
	////마지막 숫자들 다음으로 알파벳이 나오는 것을 활용하여
	////숫자를 없애기 위해 erase를 실행
	//str.erase(0, index); //삭제할 문자의 시작 인덱스, 제거할 문자의 개수
	//
	//if (sum != 0)
	//	cout << str << sum;
	//else
	//	cout << str;

	string result;
	int sum = 0;

	for (auto i : str) {
		if (isalpha(i))
			result.push_back(i);
		else
			sum += i - '0';
	}

	sort(result.begin(), result.end());
	if (sum != 0)
		result += to_string(sum); //int에서 string으로 sum을 형변환 해줘야되는거 잊지 말고
								  //result가 vector<string>이 아닌 string이기 때문에 push_back을 하면 안되고 +로 덧붙여야 함
								  //string일때 push_back은 넣으려는 문자가 char일때만 할 수 있음

	cout << result;

	return 0;
}