#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map <int, string> numName;
	map <string, int> nameNum;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		numName.insert({ i+1,name });
		nameNum.insert({ name, i + 1 });
	}

	vector<string>result;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		int num;
		
		if (isdigit(str[0])) {
			num=stoi(str);
			cout << numName[num] << "\n";
		}
		else {
			cout << nameNum[str] << "\n";
		}
		
	}
}