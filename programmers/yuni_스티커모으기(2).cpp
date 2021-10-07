#include <iostream>
#include <vector>
using namespace std;

int dp[100010];
int solution(vector<int> sticker) {
    int answer = 0;

    if (sticker.size() == 1)return sticker[0];

    //1을 선택한 경우와 2를 선택한 경우를 나눠서 생각
    
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for (int i = 2; i < sticker.size() - 1; i++) {
        int tmp = sticker[i] + dp[i - 2];
        dp[i] = max(dp[i - 1], tmp);
    }
    dp[0] = 0;
    dp[1] = sticker[1];
    answer =dp[sticker.size() - 2];
    for (int i = 2; i < sticker.size(); i++) {
        int tmp = sticker[i] + dp[i - 2];
        dp[i] = max(dp[i - 1], tmp);
    }
    answer = max(answer, dp[sticker.size() - 1]);
    return answer;
}


int main(void) {
    solution({ 14,6,5,11,3,9,2,10 });
    solution({ 1,3,2,5,4 });
}