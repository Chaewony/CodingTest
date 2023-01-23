#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int bfs(vector<vector<bool>>& vec, int n, int m, queue<tuple<int, int, int>>& myQueue)
{
    int move = 0;
    while (!myQueue.empty()) {
        int i = get<0>(myQueue.front());
        int j = get<1>(myQueue.front());
        int height = get<2>(myQueue.front());

        myQueue.pop();

        //상
        if (i - 1 >= 0) {
            if (vec[i - 1][j] != 0) {
                vec[i - 1][j] = 0;
                myQueue.push({ i - 1 , j, height+1 });
            }
        }
        //하
        if (i + 1 <= n - 1) {
            if (vec[i + 1][j] != 0) {
                vec[i + 1][j] = 0;
                myQueue.push({ i + 1 , j, height + 1 });
            }
        }
        //좌
        if (j - 1 >= 0) {
            if (vec[i][j - 1] != 0) {
                vec[i][j - 1] = 0;
                myQueue.push({ i , j - 1, height + 1 });
            }
        }
        //우
        if (j + 1 <= m - 1) {
            if (vec[i][j + 1] != 0) {
                vec[i][j + 1] = 0;
                myQueue.push({ i , j + 1, height + 1 });
            }
        }

        if (vec[n - 1][m - 1] == 0) {
            move = height + 1;
            break;
        }
    }
    
    return move;
}

int main()
{
//입력부
    int n;//세로길이(행)
    int m;//가로길이(열)
    cin >> n >> m;

    vector<vector<bool>> vec(n);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++) {
            vec[i].push_back(str[j] - '0');
        }
    }

//계산부
    int result = 0;

    queue<tuple<int, int, int>> myQueue;
    myQueue.push({ 0,0,1 }); //루트 노드 삽입
    vec[0][0] = 0;
    result = bfs(vec, n, m, myQueue);

//출력부
    cout << result;
}