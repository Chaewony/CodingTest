#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void main()
{
	//첫번째 인풋
	string string1;
	getline(cin, string1);

	stringstream stringStream1(string1);
	vector<int> firstInput;

	int tmpNumber1;

	while (stringStream1 >> tmpNumber1)
		firstInput.push_back(tmpNumber1);

	int n = firstInput[0];

	//두번째 인풋
	string string2;
	getline(cin, string2);

	stringstream stringStream2(string2);

	vector<char> secondInput;

	char tmpNumber2;

	while (stringStream2 >> tmpNumber2)
		secondInput.push_back(tmpNumber2);

	vector<int> result = { 1,1 };

	for (auto i : secondInput) {
		if (i == 'U' && result[0] != 1)
			result[0] -= 1;
		else if (i == 'D' && result[0] != n)
			result[0] += 1;
		else if (i == 'L' && result[1] != 1)
			result[1] -= 1;
		else if (i == 'R' && result[1] != n)
			result[1] += 1;
	}
	cout << result[0] << " " << result[1];
}