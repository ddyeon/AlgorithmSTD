#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000010] {};

int solution(vector<int> money) 
{
    int answer = 0;

    //첫번째 집부터 털기
    dp[0] = money[0];
    dp[1] = money[0];

    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }
    answer = max(answer, dp[money.size() - 2]);

    //두번째 집부터 털기
    dp[0] = 0;
    dp[1] = money[1];

    for (int i = 2; i < money.size(); i++) {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }
    answer = max(answer, dp[money.size() - 1]);

    return answer;
}

int main(void)
{
    vector<int> money = {1000, 1, 0, 1, 2, 1000, 0};

    cout << solution(money) << endl;

    return 0;
}