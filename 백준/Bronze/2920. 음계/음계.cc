#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string result;
	string str;
	char c;
	for (int i = 0; i < 8; i++) {
		cin >> c;
		str.push_back(c);
	}
	if (str == "12345678") {
		result = "ascending";
	}
	else if (str == "87654321") {
		result = "descending";
	}
	else {
		result = "mixed";
	}

	cout << result;
}