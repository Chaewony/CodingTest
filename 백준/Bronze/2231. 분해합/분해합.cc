#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int result = 0;
	
	for (int i = 0; i < n; i++) {
		int sum = i;
		string tmp = to_string(i);
		for (int j = 0; j < tmp.size(); j++) {
			sum += tmp[j]-'0';
		}

		if (sum == n) {
			result = i;
			break;
		}
	}

	cout << result;
}