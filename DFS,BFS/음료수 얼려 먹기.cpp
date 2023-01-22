#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<bool>>& vec, int n, int m, vector<pair<int, int>>& stack)
{
    if (stack.empty())
        return;

    int i = stack.back().first;
    int j = stack.back().second;

    //상
    if (i - 1 >= 0) {
        if (vec[i-1][j] != 1) {
            vec[i - 1][j] = 1;
            stack.push_back({ i - 1 , j });
            dfs(vec, n, m, stack);
        }
    }
    //하
    if (i + 1 <= n-1) { // i + 1 <= n가 아닌 <= n - 1으로 적어야 하는 점 주의
        if (vec[i + 1][j] != 1) {
            vec[i + 1][j] = 1;
            stack.push_back({ i + 1 , j });
            dfs(vec, n, m, stack);
        }
    }
    //좌
    if (j - 1 >= 0) {
        if (vec[i][j-1] != 1) {
            vec[i][j-1] = 1;
            stack.push_back({ i , j-1 });
            dfs(vec, n, m, stack);
        }
    }
    //우
    if (j + 1 <= m-1) {
        if (vec[i][j + 1] != 1) {
            vec[i][j + 1] = 1;
            stack.push_back({ i , j + 1 });
            dfs(vec, n, m, stack);
        }
    }

    stack.pop_back();
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

    for (int i = 0; i < n; i++) { //행의 크기만큼 반복
        for (int j = 0; j < m; j++) { //열의 크기만큼 반복
            
            //루트노드 설정
            if (vec[i][j] == 0) {
                vector<pair<int, int>> stack; //스택(1개의 아이스크림 묶음 주머니)
                stack.push_back({ i,j }); //루트 노드 삽입
                vec[i][j] = 1;
                dfs(vec, n, m, stack); //재귀함수 호출
                result++;
            }
        }
    }

//출력부
    cout << result;
}