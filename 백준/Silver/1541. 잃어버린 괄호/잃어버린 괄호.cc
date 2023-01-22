#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	if(isdigit(str[0]))
		str.insert(0, "+");

	int result = 0;
	string tmp;

	bool minus = false;
	vector<char> operators;

	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			tmp += str[i];
		}
		else
		{
			if (operators.empty()) {
				operators.push_back(str[i]);

				if (operators.back() == '-')
					minus = true;

				continue;
			}
			
			if (!minus)
				result += stoi(tmp);
			else
				result -= stoi(tmp);

			operators.push_back(str[i]);
			if (operators.back() == '-')
				minus = true;

			tmp.clear();
		}
	}

	//마지막 숫자 처리
	if (minus)
		result -= stoi(tmp);
	else
		result += stoi(tmp);

	cout << result;

}