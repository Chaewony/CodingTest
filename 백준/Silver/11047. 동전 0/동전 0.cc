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
	
	int n = firstInput[0];
	int k = firstInput[1];

	vector<int> secondInput;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		secondInput.push_back(tmp);
	}

	sort(secondInput.rbegin(), secondInput.rend());

	int count = 0;

	while (k > 0) {
		for (auto i : secondInput) {
			if (k - i >= 0) {
				k = k - i;
				count++;
				break;
			}
		}
	}

	cout << count;
}