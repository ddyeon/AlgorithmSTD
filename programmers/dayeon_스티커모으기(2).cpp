#include <iostream>
#include <vector>
using namespace std;
//첫번째꺼 듣는지 안뜯는지 구분 필요.
int dp[100001];


int solution(vector<int> sticker)
{
    int answer = 0;

    int n = sticker.size();

    if (n == 1)
        return sticker[0];

    dp[0] = sticker[0];
    dp[1] = sticker[0];


    for (int i = 2; i < n - 1; i++) //첫번째 뜯는경우
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = max(answer, dp[n - 2]);

    dp[0] = 0;
    dp[1] = sticker[1];


    for (int i = 2; i < n; i++) //첫번째 안뜯는경우
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = max(answer, dp[n - 1]);

    return answer;
}

int main()
{
    // [ 14, 6, 5, 11, 3, 9, 2, 10 ] 36
    // [1, 3, 2, 5, 4] 8
}