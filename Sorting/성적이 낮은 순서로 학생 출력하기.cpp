#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int>a, pair<string, int>b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> vec;
    for (int i = 0; i < n; i++) {
        string str;
        int m;
        cin >> str >> m;
        vec.push_back({ str, m });
    }

    sort(vec.rbegin(), vec.rend(), compare);

    for (auto i : vec) {
        cout << i.first << " ";
    }
}