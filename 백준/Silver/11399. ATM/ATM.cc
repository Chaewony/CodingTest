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

	string string2;
	getline(cin, string2);
	stringstream stringStream2(string2);
	vector<int> secondInput;
	int tmpNumber2;
	while (stringStream2 >> tmpNumber2)
		secondInput.push_back(tmpNumber2);

	sort(secondInput.begin(), secondInput.end());

	int result = 0;
	int result2 = 0;
	int tmp = 0;
	for (auto i : secondInput) {
		result = tmp + i;
		tmp = result;
		result2 = result + result2;
	}

	cout << result2;
}