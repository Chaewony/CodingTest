#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    return a.size() < b.size();
}

int main()
{
    int n;
    cin >> n;

    vector<string> vec;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    stable_sort(vec.begin(), vec.end(), compare);

    for (auto i : vec) {
        cout << i << "\n";
    }
}