#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string n,m;
    cin >> n>>m;

    string o, p;
    for (int i = 3; i > 0; i--) {
        o.push_back(n[i-1]);
    }
    for (int i = 3; i > 0; i--) {
        p.push_back(m[i - 1]);
    }

    cout << max(stoi(o), stoi(p));
}