#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int find = 0;
    int number = 665;
    while (find < n) {
        number++;
        if (to_string(number).find("666") != string::npos)
            find++;
    }
    cout << number;
}
