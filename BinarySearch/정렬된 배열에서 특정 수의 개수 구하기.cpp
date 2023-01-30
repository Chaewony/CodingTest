#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m; 
    cin >> n >> m;

    vector<long long> cards;

    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        cards.push_back(tmp);
    }

    sort(cards.begin(), cards.end());

    long long result = upper_bound(cards.begin(), cards.end(), m) - lower_bound(cards.begin(), cards.end(), m);

    if (result == 0)
        result = -1;

    cout << result;
}