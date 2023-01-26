#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) 
{
	if (get<1>(a) == get<1>(b)) {
		if (get<2>(a) == get<2>(b)) {
			if (get<3>(a) == get<3>(b)) {
				//이름
				return get<0>(a) < get<0>(b);
			}
			else {
				//수학
				return get<3>(a) > get<3>(b);
			}
		}
		else {
			//영어
			return get<2>(a) < get<2>(b);
		}
	}
	else {
		//국어
		return get<1>(a) > get<1>(b);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<tuple<string, int, int, int>> vec;

	for (int i = 0; i < n; i++) {
		string name;
		int Korean, English, Math;

		cin >> name >> Korean >> English >> Math;

		vec.push_back({ name ,Korean ,English ,Math });
	}

	sort(vec.begin(), vec.end(), compare);

	for (auto i : vec) {
		cout << get<0>(i) << "\n";
	}
}