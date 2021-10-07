#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp;
vector<int> dp2;

int solution(vector<int> money) {
    int answer = 0;

    if (money.size() == 3) {
        answer = max(money[0], money[1]);
        return max(answer, money[2]);
    }


    dp.push_back(money[0]);
    dp.push_back(money[0]);

    for (int i = 2; i < money.size() - 1; i++) {
        dp.push_back(max(dp[i - 1], money[i] + dp[i - 2]));
    }
    answer = max(answer, dp[money.size() - 2]);

    dp2.push_back(0);
    dp2.push_back(money[1]);
    dp2.push_back(max(money[1], money[2])); //왤까,,,,무조건 2만 선택하게 하고시푼뎅,,,

    for (int i = 3; i < money.size(); i++) {
        dp2.push_back(max(dp2[i - 1], money[i] + dp2[i - 2]));
    }
    answer = max(answer, dp2[money.size() - 1]);
    return answer;
}