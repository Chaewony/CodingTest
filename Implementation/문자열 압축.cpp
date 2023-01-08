//문제 링크: https://school.programmers.co.kr/learn/courses/30/lessons/60057
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = 0;

    //문자열 사이즈가 1이면
    //압축할 수 없으니 어떤 경우에도 길이가 1임
    if (s.size() == 1)
        return 1;

    vector<int> v; //압축된 문자열 길이를 저장할 벡터
    
    int repeatValue = 1; //비교대상의 문자열이 같으면 증가(반복값)
    string result; //압축된 문자열
    string tmp; //비교기준

    //i는 자를 수 있는 단위
    for (int i = 1; i <= s.size() / 2; i++){
        tmp.append(s, 0, i); //첫번째 비교 기준은 0번째 문자부터 i개를 넣음
        result.clear(); //기존에 있던 압축된 문자열을 비움
        repeatValue = 1; //반복값 초기화

        //j는 i단위로 자른 문자열(비교대상)의 개수
        for (int j = 1; j <= ceil((float(s.size()) / i)); j++) {
            string target; //비교대상

            //남은 비교 대상이 자르는 단위보다 작으면 실행
            if (j * i + i - 1 >=s.size()) { //문자열이 끝까지 있다고 치고, 문자열을 i단위로 잘랐을 때 마지막 요소가 s의 사이즈보다 크면, null을 가리키므로 다음과 같이 표현함
                //반복값이 1보다 크면 result에 반복값을 넣어줌
                if (repeatValue > 1) {
                    result.append(to_string(repeatValue));
                }
                //비교기준 넣고, 나머지 비교 대상을 넣음
                result.append(tmp);
                result.append(s, j * i, s.size() % i);
                //비교기준 초기화
                tmp.clear();
                break;
            }
            //비교대상 설정, j * i번째 문자부터 i개 만큼
            target.append(s, j * i, i);

            //비교기준과 비교대상이 같으면 repeatValue 증가
            if (tmp.compare(target)==0)
                repeatValue++;

            //비교기준과 비교대상이 다르면
            else {
                //반복값이 1보다 크면 result에 반복값을 넣어줌
                if(repeatValue>1)
                    result.append(to_string(repeatValue));
                //result에 비교기준 넣고
                result.append(tmp);
                //비교 기준을 비교 대상으로 초기화
                tmp.clear();
                tmp.append(target);
                repeatValue = 1; //repeatValue 초기화
            }
        }
        //i단위로 압축된 문자열의 사이즈를 v에 저장
        v.push_back(result.size());
    }
    //v의 요소 중 최소값
    answer = *min_element(v.begin(), v.end());

    return answer;
}

int main()
{
    string s = "aaaaaaaaaaaabcd";
    cout << solution(s);
}