#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;

    for (int i = 1; i < n+1; i++) {
        q.push(i);
    }

    cout << "<";

    int moveTimes = 0;

    while (!q.empty()) {
        if (moveTimes == m - 1) {
            cout << q.front();
            q.pop();
            moveTimes = 0;

            if (q.empty())
                break;
        }
        else {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            moveTimes++;
            continue;
        }
        cout << ", ";
    }
    cout << ">";
}
