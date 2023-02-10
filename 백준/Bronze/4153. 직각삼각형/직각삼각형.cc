#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> result;
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        if (a * a + b * b == c * c)
            result.push_back("right");
        else if (a * a + c * c == b * b)
            result.push_back("right");
        else if (b* b + c * c == a * a)
            result.push_back("right");
        else
            result.push_back("wrong");
    }
    
    for (auto i : result) {
        cout << i << "\n";
    }
}