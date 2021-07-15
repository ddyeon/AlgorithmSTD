#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s) {
    string x = string(1, s[0]);
    string tmp;
    int count = 0;
    int answer = 0, minCount = s.length();
    for (int j = 1; j <= s.length() / 2; j++) {
        answer = s.length();
        count = 0;
        for (int i = 0; i < s.length(); i += j) {
            if (j == 1) tmp = string(1, s[i]);
            else tmp = s.substr(i, j);
            if (x == tmp)count++;
            if (x != tmp) {
                if (count > 1) {
                    answer -= (count * j);
                    answer += j;
                    if (count < 10)answer += 1;
                    else if (count >= 10 && count < 100)answer += 2;
                    else if (count > 100)answer += 3;
                }
                count = 1;
            }
            x = tmp;
        }
        if (count > 1) {
            answer -= (count * j);
            answer += j;
            if (count < 10) answer += 1;
            else if (count >= 10 && count < 100)answer += 2;
            else if (count > 100 && count < 1000)answer += 3;
            else if (count == 1000) answer += 4;
        }
        if (minCount > answer) minCount = answer;
    }
    answer = minCount;
    return answer;
}