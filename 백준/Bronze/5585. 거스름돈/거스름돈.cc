#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int k = 1000 - n;
	int count = 0;
	int tmp = 0;
	while (k > 0) {
		if (k - 500 >= 0)
			tmp = 500;
		else if (k - 100 >= 0)
			tmp = 100;
		else if (k - 50 >= 0)
			tmp = 50;
		else if (k - 10 >= 0)
			tmp = 10;
		else if (k - 5 >= 0)
			tmp = 5;
		else
			tmp = 1;

		k -= tmp;
		count++;
	}

	cout << count;
}