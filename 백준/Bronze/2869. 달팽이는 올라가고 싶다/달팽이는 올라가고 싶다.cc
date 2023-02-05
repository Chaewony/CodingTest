#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long A, B, V;
    cin >> A >> B >> V;

    long long result = (V - A) / (A - B);

    if ((V - A) % (A - B)==0) {
        cout << result + 1;
        return 0;
    }  
    cout << result + 2;
}