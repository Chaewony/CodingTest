#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	vector<string> results;

	while (true) {
		string s;
		cin >> s;

		if (s == "0")
			break;

		vector<char> c;
		for (int i = 0; i < s.size()/2; i++) {
			c.push_back(s[i]);
		}

		for (int i = ceil((float)s.size() / 2); i < s.size(); i++) {
			if (c.back() == s[i]) {
				c.pop_back();
				continue;
			}
			else {
				break;
			}
		}

		if (c.empty()) 
			results.push_back("yes");
		else
			results.push_back("no");
	}

	for (auto i : results)
		cout << i << "\n";
}