#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> keys;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        keys.push_back(m);
    }

    int max = *max_element(keys.begin(), keys.end());

    vector<int> vec(max+1, 0);
    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 4;

    for (int i = 4; i < max + 1; i++) {
        vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
    }

    for (int i = 0; i < n; i++) {
        cout << vec[keys[i]] << "\n";
    }
}