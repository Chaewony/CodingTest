#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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

	int n = firstInput[0]; //공의 개수
	int k = firstInput[1]; //바구니(팀)의 개수

	int least = 0;
	for (int m = 1; m <= k; m++) {
		least += m;
	}

	if (least > n) {
		cout << -1;
		return 0;
	}

	if ((n - least) % k == 0) {
		cout << k - 1;
	}
	else
		cout << k;
}