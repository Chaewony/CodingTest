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

	int result = 0;

	while (!distances.empty()) {
		int min = *min_element(prices.begin(), prices.end() - 1);
		int minIndex = min_element(prices.begin(), prices.end() - 1) - prices.begin();

		result += prices[minIndex] * accumulate(distances.begin() + minIndex, distances.end(), 0);
		distances.erase(distances.begin() + minIndex, distances.end());
		prices.erase(prices.begin() + minIndex, prices.end());
	}
	
	cout << result;
}