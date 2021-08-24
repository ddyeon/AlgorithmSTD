#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int ans[3] = { 0 };
int solution(string dartResult) {
    int answer = 0;
    int ansIndex = -1;
    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] - '0' >= 0 && dartResult[i] - '0' <= 9) {
            ansIndex++;
            if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
                i++;
                ans[ansIndex] = 10;
            }
            else
                ans[ansIndex] = dartResult[i] - '0';

        }

        else if (dartResult[i] == 'D')
            ans[ansIndex] = ans[ansIndex] * ans[ansIndex];

        else if (dartResult[i] == 'T')
            ans[ansIndex] = ans[ansIndex] * ans[ansIndex] * ans[ansIndex];

        else if (dartResult[i] == '*') {
            if (ansIndex > 0)
                ans[ansIndex - 1] *= 2;
            ans[ansIndex] *= 2;
        }

        else if (dartResult[i] == '#')
            ans[ansIndex] = -ans[ansIndex];

    }
    for (int i = 0; i < 3; i++)
        answer += ans[i];
    return answer;
}