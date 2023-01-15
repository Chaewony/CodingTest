#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    int result = 1;

    while (n < m) {
        if ((m-1)%10==0) {
            m = (m - 1) / 10;
        }
        else if (m % 2 == 0) {
            m = m / 2;
        }
        else {
            cout << -1;
            return 0;
        }
        result++;
    }

    if (n == m)
        cout << result;
    else
        cout << -1;

}