#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 연산자 우선순위??
// 1. S, D, T의 적용
// 2. *, #의 적용
int solution(string dartResult)
{
    int answer = 0;
    vector<string> calculate;

    // S, D, T의 적용
    for (int i = 1; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S') {
            if (dartResult[i - 2] >= 0 && dartResult[i - 2] == '1') {
                calculate.push_back(to_string(10));
            }
            else {
                calculate.push_back(dartResult.substr(i - 1, 1));
            }
        }
        else if (dartResult[i] == 'D') {
            if (dartResult[i - 2] >= 0 && dartResult[i - 2] == '1') {
                calculate.push_back(to_string(100));
            }
            else {
                int tmp = dartResult[i - 1] - '0';
                tmp = tmp * tmp;
                calculate.push_back(to_string(tmp));
            }            
        }
        else if (dartResult[i] == 'T') {
            if (dartResult[i - 2] >= 0 && dartResult[i - 2] == '1') {
                calculate.push_back(to_string(1000));
            }
            else {
                int tmp = dartResult[i - 1] - '0';
                tmp = tmp * tmp * tmp;
                calculate.push_back(to_string(tmp));
            }  
        }
        else if (dartResult[i] == '*' || dartResult[i] == '#') {
            calculate.push_back(dartResult.substr(i, 1));
        }
    }

    // *, #의 적용
    for (int i = 0; i < calculate.size(); i++) {
        if (calculate[i] == "*") {
            calculate[i - 1] = to_string(stoi(calculate[i - 1]) * 2);
            if (i - 2 >= 0) {
                calculate[i - 2] = to_string(stoi(calculate[i - 2]) * 2);
            }
            calculate.erase(calculate.begin() + i);
            i--;
        }
        else if (calculate[i] == "#") {
            calculate[i - 1] = to_string(stoi(calculate[i - 1]) * -1);
            calculate.erase(calculate.begin() + i);
            i--;
        }
    }

    // 다 더하기
    for (auto i : calculate) {
        answer += stoi(i);
    }

    return answer;
}

int main(void)
{
    string dartResult = "1D2S#10S";

    cout << solution(dartResult) << endl;;

    return 0;
}