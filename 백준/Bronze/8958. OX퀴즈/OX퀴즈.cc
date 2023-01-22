#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec;
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int tmp = 0;
        int result = 0;
        for (auto j : str) {
            if (j == 'O') {
                tmp++;
                result += tmp;
            }
            else {
                tmp = 0;
            } 
        }
        vec.push_back(result);
    }

    for (auto i : vec) {
        cout << i << "\n";
    }
}