#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vec.push_back(m);
    }

    sort(vec.rbegin(), vec.rend());

    for (auto i : vec) {
        cout << i << " ";
    }
}