#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> vec;

    for (int i = 0; i < n; i++) {
        int m;
        string str;
        
        string tmp;

        cin >> m >> str;
        
        for (int j = 0; j < str.size(); j++) {
            for (int k = 0; k < m; k++) {
                tmp.push_back(str[j]);
            }
        }
        vec.push_back(tmp);
    }

    for (auto i : vec) {
        cout<<i<<"\n";
    }
}