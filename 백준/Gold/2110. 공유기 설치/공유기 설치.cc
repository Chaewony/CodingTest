#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
   
    vector<long long> houses;
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        houses.push_back(tmp);
    }
    sort(houses.begin(), houses.end());

    long long start = 1;
    long long end = houses.back() - houses[0];

    long long result = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long routers = 1;
        long long prev = houses[0];

        for (int i = 1; i < n; i++) {
            if (houses[i] - prev >= mid) {
                routers++;
                prev = houses[i];
            }
        }

        if (routers >= m) {
            start = mid + 1;
            result = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << result;
}
