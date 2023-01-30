#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    long long start = 0;
    long long end = vec.size();
    long long result = -1;
    while (start <= end) {
        long long mid = (start + end) / 2;
        if (vec[mid] < mid) {
            start = start + 1;
        }
        else if (vec[mid] > mid) {
            end = end - 1;
        }
        else {
            result = mid;
            break;
        }
    }
    cout << result;
}
