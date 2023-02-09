#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> vec(10001,0);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vec[m]++;
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i]; j++) {
            cout << i << "\n";
        }
    }
}