#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = 0;

    if (s.size() == 1)
        return 1;

    vector<int> v;
    
    int repeatValue = 1;
    string result;
    string tmp;
    for (int i = 1; i <= s.size() / 2; i++){
        tmp.append(s, 0, i);
        result.clear();
        repeatValue = 1;
        for (int j = 1; j <= ceil((float(s.size()) / i)); j++) {
            string target;
            if (j * i + i - 1 >=s.size()) {
                if (repeatValue > 1) {
                    result.append(to_string(repeatValue));
                    //result.append(tmp);
                }
                //else {
                ////    result.append(s, result.size(), s.size() - result.size());
                //    result.append(tmp);
                //    result.append(s, j * i, s.size() % i);
                //}
                result.append(tmp);
                result.append(s, j * i, s.size() % i);
                tmp.clear();
                break;
            }

            target.append(s, j * i, i);
            
            /*if (target.size() == 0) {
                result.append(tmp);
                tmp.clear();
            }*/

            if (tmp.compare(target)==0)
                repeatValue++;
            else {
                if(repeatValue>1)
                    result.append(to_string(repeatValue));
                result.append(tmp);
                tmp.clear();
                tmp.append(target);
                repeatValue = 1;
            }
        }
        v.push_back(result.size());
    }

    sort(v.begin(), v.end());
    answer = v[0];

    return answer;
}