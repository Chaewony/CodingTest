#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	transform(str.begin(), str.end(), str.begin(), ::toupper);

	sort(str.begin(), str.end());

	string alphabets(str);
	alphabets.erase(unique(alphabets.begin(), alphabets.end()), alphabets.end());
	
	vector<int> result(alphabets.size(), 0);

	char tmp = '0';
	int index = -1;
	for (int i = 0; i < str.size(); i++) {
		if (tmp != str[i]) {
			index++;
			tmp = str[i];
		}
		result[index]++;
	}

	int tmp2 = result[0];
	vector<int> result2;
	result2.push_back(0);
	for (int i = 1; i < result.size(); i++) {
		if (tmp2 < result[i]) {
			result2.clear();
			result2.push_back(i);
			tmp2 = result[i];
		}
		else if (tmp2 == result[i]) {
			result2.push_back(i);
		}
	}

	if (result2.size() > 1) {
		cout << "?";
	}
	else
		cout << alphabets[result2.back()];
}