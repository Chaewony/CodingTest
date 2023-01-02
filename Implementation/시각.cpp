#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main()
{
	int n;
	cin >> n;

	int count = 0;

	//처음에 푼 방법
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 59; j++) {
			for (int k = 0; k <= 59; k++) {
				if ((i % 10 == 3) || (j % 10 == 3 || (j >= 30 && j <= 39)) || (k % 10 == 3 || (k >= 30 && k <= 39)))
					count++;
			}
		}
	}*/
	
	//풀이대로 푼 방법
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 59; j++) {
			for (int k = 0; k <= 59; k++) {
				if ((to_string(i) + to_string(j) + to_string(k)).find('3') != std::string::npos)
					count++;
			}
		}
	}

	cout << count;
}