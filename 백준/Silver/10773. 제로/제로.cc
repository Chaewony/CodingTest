#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    long long result = 0;
    vector<long long> vec;

    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
       
        if (tmp == 0) {
            result -= vec.back();
            vec.pop_back();
        }
        else {
            vec.push_back(tmp);
            result += tmp;
        }
    }

    cout << result;
}
