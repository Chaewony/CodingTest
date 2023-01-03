#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void main()
{
	string string1;
	getline(cin, string1);
	stringstream stringStream1(string1);
	vector<int> firstInput;
	int tmpNumber1;
	while (stringStream1 >> tmpNumber1)
		firstInput.push_back(tmpNumber1);

	int n = firstInput[0]; //세로 길이, 행, x
	int m = firstInput[1]; //가로 길이, 열, y

	string string2;
	getline(cin, string2);
	stringstream stringStream2(string2);
	vector<int> secondInput;
	int tmpNumber2;
	while (stringStream2 >> tmpNumber2)
		secondInput.push_back(tmpNumber2);

	int xPos = secondInput[0]; //x좌표
	int yPos = secondInput[1]; //y좌표
	int dir = secondInput[2]; //현재방향

	vector<vector<int>> map(n); //맵
	for (int i = 0; i < n; i++) {
		string string3;
		getline(cin, string3);
		stringstream stringStream3(string3);
		int tmpNumber3;
		while (stringStream3 >> tmpNumber3)
			map[i].push_back(tmpNumber3);
	}

	//현위치를 맵에서 가본 칸으로 바꿈 (안가본 칸:0, 바다:1, 가본 칸:2)
	map[xPos][yPos] = 2;
	int movingCount = 1; //방문 칸 수
	int rotCount = 0; //회전 횟수

	//선택지
	vector<vector<int>> steps = { {-1,0},{0,1},{1,0},{0,-1} }; //인덱스: 0(북), 1(동), 2(남), 3(서)

	while (true) {
		//현재 방향에서 왼쪽 방향으로 회전
		dir = (dir + 3) % 4;
		rotCount++;
		//전진할 칸이 맵 안에 있는가?
		if (xPos + steps[dir][0] >= 0 && xPos + steps[dir][0] <= n
			&& yPos + steps[dir][1] >= 0 && yPos + steps[dir][1] <= m) {
			int debug1 = xPos + steps[dir][0];
			int debug2 = yPos + steps[dir][1];
			// 전진시 아직 가보지 않은 칸인가?
			if (map[xPos + steps[dir][0]][yPos + steps[dir][1]] == 0) {
				//전진
				xPos += steps[dir][0];
				yPos += steps[dir][1];

				//맵에서 가본 칸으로 바꿈
				map[xPos][yPos] = 2;

				movingCount++;
				rotCount = 0;
			}

		}

		//네 방향 모두 이미 가본 칸이거나 바다로 되어있는 경우
		if (rotCount == 4) {
			
			//후진할 칸이 맵 안에 있는가?
			if (xPos - 1 * steps[dir][0] >= 0 && xPos - 1 * steps[dir][0] <= n
				&& yPos - 1 * steps[dir][1] >= 0 && yPos - 1 * steps[dir][1] <= m) {

				// 후진시 바다가 아닌가?
				if (map[xPos - 1 * steps[dir][0]][yPos - 1 * steps[dir][1]] != 1) {
					//후진
					xPos -= steps[dir][0];
					yPos -= steps[dir][1];

					rotCount = 0;
				}
				else
					break;

			}
			else
				break;
		}
	}

	cout << movingCount;
	
	
}