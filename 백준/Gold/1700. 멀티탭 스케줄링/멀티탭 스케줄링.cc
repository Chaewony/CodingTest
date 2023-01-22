#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string string1;
    getline(cin, string1);
    stringstream stringStream1(string1);
    vector<int> firstInput;
    int tmpNumber1;

    while (stringStream1 >> tmpNumber1)
        firstInput.push_back(tmpNumber1);

    int n = firstInput[0];
    int k = firstInput[1];


    string string2;
    getline(cin, string2);
    stringstream stringStream2(string2);
    vector<int> secondInput;
    int tmpNumber2;

    while (stringStream2 >> tmpNumber2)
        secondInput.push_back(tmpNumber2);

    int result = 0;
    vector<int> power;
    for (int i = 0; i < k; i++) {
        //빈 자리가 있으면
        if (power.size() < n) {
            //꽂으려는 플러그가 콘센트에 꽂혀있지 않으면
            if (find(power.begin(), power.end(), secondInput[i]) == power.end()) {
                power.push_back(secondInput[i]);
            }            
        }
        //빈 자리가 없으면
        else {
            int tmp = 0;
            auto adress = secondInput.begin();
            //꽂으려는 플러그가 콘센트에 꽂혀있지 않으면
            if (find(power.begin(), power.end(), secondInput[i]) == power.end()) {
                result++;
                
                //콘센트에서 뽑을 플러그를 정하는 과정
                for (auto o : power) {
                    auto it = find(secondInput.begin()+i, secondInput.end(), o);
                    //target 플러그가 이후에 꽂을 예정이 아니면
                    if (it == secondInput.end()) {
                        power.erase(remove(power.begin(), power.end(), o), power.end()); // 바로 해당 플러그를 뽑음
                        break;
                    }
                    else {
                        if (adress < it) {
                            tmp = *it; //기존의 최댓값과 비교하여 더 크면 이것을 최댓값으로 저장
                            adress = it;
                        }
                    }
                }

                //최댓값을 가진 플러그를 뽑음
                if (power.size() == n) {
                    power.erase(remove(power.begin(), power.end(), tmp), power.end());
                }

                //이제 power에 플러그를 꽂음
                power.push_back(secondInput[i]);
            }
        }
    }

    cout << result;
}