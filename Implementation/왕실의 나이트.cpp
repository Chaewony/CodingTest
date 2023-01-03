#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main()
{
	string n;
	cin >> n;

	//char 자료형에 임시로 담기
	char tmpX = n[0]; //0번째는 x값(위치)
	char tmpY = n[1]; //1번째는 y값(위치)

	//x값을 int형으로 바꿔주기 위해
	//string x 문자열에서 tmpX가 있는 위치를 확인
	//원래는 0부터 세어주니까 문제와 같도록 1을 더함
	string x = "abcde";

	int xPos = x.find(tmpX) + 1;
	int yPos = tmpY - '0'; 

	int count = 0;
	
	//방법 1
	/*if (xPos + 2 >= 1 && xPos + 2 <= 8) {
		if (yPos - 1 >= 1 && yPos - 1 <= 8)
			count++;
		if (yPos + 1 >= 1 && yPos + 1 <= 8)
			count++;
	}
	if (xPos - 2 >= 1 && xPos - 2 <= 8) {
		if (yPos - 1 >= 1 && yPos - 1 <= 8)
			count++;
		if (yPos + 1 >= 1 && yPos + 1 <= 8)
			count++;
	}
	if (yPos + 2 >= 1 && yPos + 2 <= 8) {
		if (xPos - 1 >= 1 && xPos - 1 <= 8)
			count++;
		if (xPos + 1 >= 1 && xPos + 1 <= 8)
			count++;
	}
	if (yPos - 2 >= 1 && yPos - 2 <= 8) {
		if (xPos - 1 >= 1 && xPos - 1 <= 8)
			count++;
		if (xPos + 1 >= 1 && xPos + 1 <= 8)
			count++;
	}*/

	//방법2
	//갈 수 있는 경로를
	//{{x0,y0},{x1,y1}, ... , {xN,yN}} 이런식으로 표현하면 보기 쉽다
	vector<vector<int>> v = { {2,-1},{2,1},{-2,-1},{-2,1},{1,-2}, {-1,-2},{1,2},{-1,2} };

	for (int i = 0; i < v.size(); i++) {
		if (xPos + v[i][0] >= 1 && xPos + v[i][0] <= 8 && yPos + v[i][1] >= 1 && yPos + v[i][1] <= 8) //어떤 갈 수 있는 경로를 채택했을 때 1이상 8이하면 유효함
			count++;
	}
	cout << count;
}