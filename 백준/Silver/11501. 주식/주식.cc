#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

int main()
{
    string string1;
    getline(cin, string1);
    stringstream stringStream1(string1);
    int n;
    stringStream1 >> n;

    vector<int> v;
    vector<long long> result;

    for (int i = 0; i < n; i++) {
        string string2;
        getline(cin, string2);
        stringstream stringStream2(string2);
        int m;
        stringStream2 >> m;

        vector<int> input;
        string string3;
        getline(cin, string3);
        stringstream stringStream3(string3);
        int tmpNumber;
        while (stringStream3 >> tmpNumber) {
            input.push_back(tmpNumber);
            v.push_back(tmpNumber);
        }

        long long having = 0;
        long long profit = 0;

        long long max = 0;
        for (int k = m - 1; k > -1; k--) {
            if (max < v[k]) {
                profit = profit + max * having;
                max = v[k];
                having = 0;
            }
            else {
                profit = profit - v[k];
                having++;
            }
        }
        profit = profit + max * having;
        result.push_back(profit);
        v.clear();
    }

    for (auto i : result) {
        cout << i << endl;
    }
}