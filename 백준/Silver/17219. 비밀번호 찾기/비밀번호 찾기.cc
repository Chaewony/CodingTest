#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,m;
	cin >> n>>m;

	map <string, string> map;
	for (int i = 0; i < n; i++) {
		string site, pw;
		cin >> site >> pw;

		map.insert({ site,pw });
	}

	vector<string>result;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		result.push_back(map[str]);
	}

	for (auto i : result) {
		cout << i << "\n";
	}
}
