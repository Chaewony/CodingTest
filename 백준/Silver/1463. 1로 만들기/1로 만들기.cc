#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> vec;

    vec.push_back(0); //인덱스 맞추기 위해 v[0] = 0
    vec.push_back(0); //v[1] = 0

    for (long long i = 2; i < n + 1; i++) {
        
        long long min = 1000001;

        if (i % 3 == 0) {
            min = 1 + vec[i / 3];
        }
        if (i % 2 == 0) { 
            if (min > 1 + vec[i / 2])
                min = 1 + vec[i / 2];
        }
        if (min > 1 + vec[i - 1])
            min = 1 + vec[i - 1];
        
        vec.push_back(min);
    }

    cout << vec[n];
}
