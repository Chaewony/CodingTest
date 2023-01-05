#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//second 값에 대해 오름차순(second 값이 같으면 first값에 대해 오름차순) 정렬
bool compare(pair<int, int> a, pair<int, int>b) {
    // 그냥 return a.second < b.second;만 하면 효율성에서 실패함
    // 그래서 a.second == b.second인 경우에 대한 판별식을 추가로 제시함
    // second 값은 index +1 값이라 a.second == b.second인 경우가 없을텐데...

    // second 값이 같으면
    // first값에 대해 오름차순
    if (a.second == b.second) { 
        return a.first < b.first;
    }
    //second 값에 대해 오름차순
    else {
        return a.second < b.second;
    }
}
//요약: 
// 걸리는 시간 기준으로 정렬
// K시간 안에 다 먹을 수 있는 음식 요소들을 삭제 (탐색 시간때문에 증가하는 시간복잡도를 줄이기 위함)
// K시간 안에 다 못먹는 음식은 음식 번호 순 대로 정렬 후 남은 시간 중 마지막으로 먹는 음식 출력

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    //vector pair 만들기 (먹을 음식)
    //first: 음식 먹는데 걸리는 시간, second: 음식 번호
    vector<pair<int, int> > v;
    for (int i = 0; i < food_times.size(); i++) {
        v.push_back(pair<int, int>(food_times[i], i + 1));
    }

    //역순 정렬
    //가장 작은 수 부터 pop 해주기 위해 역순으로(내림차순) 정렬함
    sort(v.rbegin(), v.rend());

    long long currentTime = 0; //최근 먹은 음식의 food_times(최근에 먹은 음식을 먹는데 걸리는 시간, 최근에 삭제한 요소의 first)
    int leftFood = food_times.size(); //남은 음식 수

    while (!v.empty()) { //음식 다먹었으면 빠져나오기
        if (currentTime == v.back().first) { //최근 먹은 음식이랑 현재 음식의 food_times가 같으면
                                             //최근 먹은 음식을 먹을 때 같이 먹었다고 판단
            v.pop_back(); //그래서 먹을 음식에서 빼줌 
            leftFood--; //남은 음식 개수 감소
            continue;
        }
        if (k >= leftFood * (v.back().first - currentTime)) { // k - leftFood * (v.back().first - currentTime) 가 0보다 크거나 같으면 
                                                              // k시간 이전에 현재 음식을 다 먹을 수 있음
            k -= leftFood * (v.back().first - currentTime); //그래서 다 먹었다 치고 먹고 난 뒤 남은 k시간을 계산해줌
            currentTime = v.back().first; // 최근 먹은 음식의 food_times를 기억함
            v.pop_back(); //그리고 먹을 음식에서 빼줌 
            leftFood--; //남은 음식 개수 감소
        }
        else
            break; //k시간 이전에 현재 음식을 다 먹을 수 없으므로 빠져나옴
    }

    if (v.empty())
        return -1; //빠져나왔을 때 먹을 음식이 비어있으면 k 이전에 음식을 다 먹은것이므로 -1을 리턴

    //loop를 빠져나온 뒤로는 번호 순 대로 음식을 먹음
    //현재 first를 기준으로 내림차순 정렬 되어있기 때문에
    //second를 기준으로 오름차순 정렬
    //sort(시작 주소, 종료 주소, [비교함수]) 
    sort(v.begin(), v.end(), compare);

    //K시간이 될때까지 0이 되는 음식이 없으므로 
    //마지막으로 먹는 음식을 그냥 계산해주면 됨
    answer = v[k % leftFood].second;

    return answer;
}