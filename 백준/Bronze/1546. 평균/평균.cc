#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vec.push_back(m);
        if (max < m)
            max = m;
    }

    float avg = 0;
    for(auto i:vec){
        avg += (float)i / max * 100;
    }

    avg = avg / n;

    cout << avg;
}