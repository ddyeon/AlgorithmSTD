#include <string>
#include <vector>

using namespace std;

int dp1[1000001];
int dp2[1000001];

//첫번째 터는 경우 -> 마지막 못털음
//두번째 터는 경우
int solution(vector<int> money)
{
    int answer = 0;
    int len = money.size()-1;

    dp1[0] = money[0];
    dp1[1] = money[0];

    dp2[0] = 0;
    dp2[1] = money[1];

    for(int i = 2; i< money.size(); i++)
    {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }

    dp2[len] = max(dp2[len-2]+ money[len], dp2[len-1]);

    answer = max(dp1[len-1], dp2[len]);

    return answer;
}