#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<int, string, int>a, tuple<int, string, int>b)
{
	if (get<0>(a) == get<0>(b))
		return get<2>(a) < get<2>(b);
	else
		return get<0>(a) < get<0>(b);
}

int main()
{
	int n;
	cin >> n;

	vector<tuple<int, string, int>>vec;

	for (int i = 0; i < n; i++) {
		int a; string n;
		cin >> a >> n;

		vec.push_back({ a,n,i });
	}

	sort(vec.begin(), vec.end(), compare);
	
	for (auto i : vec) {
		cout << get<0>(i)<< " " << get<1>(i) << "\n";
	}
}
