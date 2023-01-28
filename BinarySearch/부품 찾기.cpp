#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(long long start, long long end, long long mid, long long target, vector<long long> vec)
{
    while (start <= end) {
        if (target > vec[mid]) {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else if (target < vec[mid]) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        else {
            return true;
        }
    }

    return false;
}

int main()
{
    long long n;
    cin >> n;

    vector<long long> vec;

    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    long long m;
    cin >> m;

    vector<long long> targets;

    for (long long i = 0; i < m; i++) {
        long long tmp;
        cin >> tmp;
        targets.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    vector<string> results;

    long long start = 0;
    long long end = vec.size();
    long long mid = vec.size() / 2;

    for (int i = 0; i < m; i++) {
        results.push_back(binarySearch(start, end, mid, targets[i], vec) ? "yes" : "no");
    }

    for (auto i : results) {
        cout << i << "\n";
    }
}