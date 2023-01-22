#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
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

	int numberOfCities = firstInput[0];

	string string2;
	getline(cin, string2);
	stringstream stringStream2(string2);
	vector<int> distances;
	int tmpNumber2;
	while (stringStream2 >> tmpNumber2)
		distances.push_back(tmpNumber2);

	string string3;
	getline(cin, string3);
	stringstream stringStream3(string3);
	vector<int> prices;
	int tmpNumber3;
	while (stringStream3 >> tmpNumber3)
		prices.push_back(tmpNumber3);

	int least = prices[0];
	long long result = 0;

	for (int i = 0; i < numberOfCities - 1; i++) {
		result += (long long) least * distances[i];
		if (prices[i] > prices[i + 1]) {
			least = prices[i + 1];
		}
	}
	cout << result;
}