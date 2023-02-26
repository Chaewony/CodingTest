#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map <string, int> names;
	map <string, int> names2;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		names.insert({ name, i});
	}

	int count = 0;

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		
		names2.insert({ str, i });

		if (names.find(str) != names.end()) {
			count++;
		}
	}

	cout << count << "\n";
	for (auto i : names2) {
		if (names.find(i.first) != names.end()) {
			cout << i.first << endl;
		}
	}
	
}