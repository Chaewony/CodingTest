#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;

		vec.push_back(m);
	}

	sort(vec.begin(), vec.end());

	cout << vec[ceil((float)vec.size() / 2)-1];
}