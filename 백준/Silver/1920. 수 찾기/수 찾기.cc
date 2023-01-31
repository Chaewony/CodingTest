#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long n, m;
    cin >> n;
    vector<long long> A;
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    cin >> m;
    vector<long long> B;
    for (long long i = 0; i < m; i++) {
        long long tmp;
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(), A.end());

    for (auto i : B) {
        long long result = upper_bound(A.begin(), A.end(), i) - lower_bound(A.begin(), A.end(), i);
        if (result == 0) {
            cout << 0 << "\n";
        }
        else
            cout << 1 << "\n";
    }
}