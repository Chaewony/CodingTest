#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    string string1;
    getline(cin, string1);
    stringstream stringStream1(string1);
    int n;
    stringStream1 >> n;

    vector<int> a;
    string string2;
    getline(cin, string2);
    stringstream stringStream2(string2);
    int tmpNumber2;
    while (stringStream2 >> tmpNumber2) {
        a.push_back(tmpNumber2);
    }

    vector<int> b;
    string string3;
    getline(cin, string3);
    stringstream stringStream3(string3);
    int tmpNumber3;
    while (stringStream3 >> tmpNumber3) {
        b.push_back(tmpNumber3);
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result + (a[i] * b[i]);
    }
    cout << result;
}