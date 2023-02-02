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

    long long start = 1;
    long long end = vec.back();

    long long result = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long sum = 0;

        for (long long i = 0; i < n; i++) {
            sum += vec[i] / mid;
        }

        if (sum >= m) {
            start = mid + 1;
            result = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << result;
}
