#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n+1,0);

	vec[0] = -1;
	vec[1] = -1;
	vec[2] = -1;
	vec[3] = 1;
	vec[4] = -1;
	vec[5] = 1;

	for (int i = 6; i < n + 1; i++) {
		if (vec[i - 5] != -1)
			vec[i] = 1 + vec[i - 5];
		else if (vec[i - 3] != -1)
			vec[i] = 1 + vec[i - 3];
		else
			vec[i] = -1;
	}

	cout << vec[n];
}