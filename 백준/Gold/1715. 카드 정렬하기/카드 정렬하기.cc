#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

int main()
{
    //입력부
    long long n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        long long m;
        cin >> m;
        pq.push(m);
    }

    //계산부
    //숫자 카드 덱이 하나라면 비교할 필요 없기 때문에 0번
    if (pq.size() == 1) {
        cout << 0;
        return 0;
    }

    long long result = 0;
    long long answer = 0;
    while (pq.size()>1) {
        result = pq.top();
        pq.pop();
        result = result + pq.top();
        pq.pop();
        pq.push(result);
        answer += result;
    }

    cout << answer;
}    