#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m;
    cin >> m;
    string n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n.size(); i++) {
        result += n[i] - '0';
    }
    cout << result;
}