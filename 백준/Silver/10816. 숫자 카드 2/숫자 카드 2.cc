#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n; 
    cin >> n;

    vector<long long> cards;

    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        cards.push_back(tmp);
    }

    sort(cards.begin(), cards.end());

    long long m;
    cin >> m;

    vector<long long> targets;

    for (long long i = 0; i < m; i++) {
        long long tmp;
        cin >> tmp;
        targets.push_back(tmp);
    }

    vector<long long> results;

    for (auto i : targets) {
        results.push_back(upper_bound(cards.begin(), cards.end(), i) - lower_bound(cards.begin(), cards.end(), i));
    }
    
    for (auto i : results) {
        cout << i << " ";
    }
}