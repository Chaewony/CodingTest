#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string n;
    cin >> n;

    sort(n.rbegin(), n.rend());

    unsigned long long sum = 0;

    for (int i = 0; i < n.size(); i++) {
        sum += (long long) n[i] - '0';
    }
    
    if (sum % 3 == 0 && n[n.size() - 1] - '0' == 0)
        cout << n;
    else
        cout << -1;
}