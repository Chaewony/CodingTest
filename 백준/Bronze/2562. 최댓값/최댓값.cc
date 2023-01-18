#include <iostream>
using namespace std;

int main()
{
    int n;
    int max = 0;
    int index = 1;
    for (int i = 0; i < 9; i++) {
        cin >> n;
        if (max < n) {
            max = n;
            index = i + 1;
        }
    }
    cout << max << endl;
    cout << index;
}