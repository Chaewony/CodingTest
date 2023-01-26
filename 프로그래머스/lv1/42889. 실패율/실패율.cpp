#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<int, int>> vec;
    for (int i = 1; i <= N + 1; i++) {
        vec.push_back({ i,0 });
    }

    for (int i = 0; i < stages.size(); i++) {
        vec[stages[i] - 1].second++;
    }

    sort(vec.rbegin(), vec.rend());

    int players = 0;
    vector<pair<int, float>> failure;
    for (int i = 0; i < vec.size(); i++) { 
        players += vec[i].second;
        if (i > 0) {
            if(players==0)
                failure.push_back({ N - i + 1, 0 });
            else
                failure.push_back({ N - i + 1, (float) vec[i].second / (float) players });
        }
    }

    sort(failure.begin(), failure.end(), compare);

    for (auto i : failure) {
        answer.push_back(i.first);
    }

    return answer;
}