#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
//입력부
    long long n, m;
    cin >> n >> m;

    vector<long long> A;
    vector<long long> B;

    long long tmp;

    for (int j = 0; j < n; j++) {
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int j = 0; j < n; j++) {
        cin >> tmp;
        B.push_back(tmp);
    }

//계산부
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    long long result = 0;
    long long index = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < B[index] && index < m) {
            result += B[index];
            index++;
        }
        else
            result += A[i];
    }

    cout << result;
}