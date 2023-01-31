#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n ;
   
    vector<long long> vec;
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());

    long long m;
    cin >> m;

    long long start = vec[0];
    long long end = vec.back();

    long long result = m / n;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long sum = 0;
        for (auto i : vec) {
            if (mid <= i)
                sum += mid;
            else
                sum += i;
        }

        if (sum == m) {
            result = mid;
            break;
        }
        else if (sum < m) { 
            result = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << result;
}
