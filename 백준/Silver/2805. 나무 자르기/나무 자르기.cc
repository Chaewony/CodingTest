#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m; 
    cin >> n >> m;

    vector<long long> vec;

    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    long long start = 0;
    long long end = vec.back();
    long long mid;

    long long result = 0;

    while (start <= end) {
        long long total = 0;
        mid = (start + end) / 2;

        for (auto i : vec) {
            if (i > mid)
                total += i - mid;
        }

        if (total >= m) {
            start = mid + 1;
            result = mid;
        }
        else if (total < m) {
            end = mid - 1;
        }
    }

    cout << result;
}