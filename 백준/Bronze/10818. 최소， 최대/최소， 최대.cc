#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> vec;
    long long m;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vec.push_back(m);
    }

    cout << *min_element(vec.begin(), vec.end()) << " " << *max_element(vec.begin(), vec.end());
}