#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

int main()
{
	string sInput1;
	getline(cin, sInput1);
	stringstream ss(sInput1);
	vector<int> input1;
	int tmp;
	while (ss >> tmp)
		input1.push_back(tmp);

	int n = input1[0];

	string sInput2;
	getline(cin, sInput2);
	stringstream ss2(sInput2);
	vector<int> input2;
	int tmp2;

	while (ss2 >> tmp2)
		input2.push_back(tmp2);

	sort(input2.begin(), input2.end());

	int target = 1;
	for (auto i : input2) {
		if (target < i)
			break;
		target += i;
	}

	cout << target;
	return 0;
}