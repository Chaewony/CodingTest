#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int start, finish;

		cin >> start >> finish;
		v.push_back(make_pair(start, finish));
	}

	sort(v.begin(), v.end());

	vector<pair<int, int>> v2;
	v2.push_back(v[0]);

	for (int i = 1; i < n; i++) {
		if (v2.back().second <= v[i].first)
			v2.push_back(v[i]);
		else {
			if (v2.back().second > v[i].second) {
				v2.pop_back();
				v2.push_back(v[i]);
			}
		}
	}

	cout << v2.size();
}