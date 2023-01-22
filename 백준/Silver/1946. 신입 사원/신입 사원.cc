#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	vector<int> result;
	int member = 0;

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;

		for (int j = 0; j < m; j++) {
			int fir, sec;

			cin >> fir >> sec;
			v.push_back(make_pair(fir, sec));
		}
		sort(v.begin(), v.end());
		//계산
		member = m;
		int top = v[0].second;
		for (int k = 1; k < m; k++) {
			if (v[k].second > top)
				member--;
			else
				top = v[k].second;
		}
		result.push_back(member);
		v.clear();
		member = 0;
	}

	for (auto i : result) {
		cout << i << endl;
	}
}