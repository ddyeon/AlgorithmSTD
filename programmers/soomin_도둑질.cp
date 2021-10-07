//
//  main.cpp
//  soomin_도둑질
//
//  Created by 김수민 on 2021/08/10.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int dp[1000001] = {0,};
    int dp2[1000001] = {0, };
    dp[0] = money[0];
    dp[1] = money[0];
    //첫번째 집 털었을 때
    for (int i = 2; i < money.size(); i++){
        if (i == money.size() - 1){
            dp[i] = dp[i - 1];
        }
        else{
            dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
        }
    }
    //첫번째집 안털었을 때
    dp2[1] = money[1];
    for (int i = 2 ; i<money.size(); i++){
        if (i == money.size() - 1){
            dp2[i] = max(dp2[i-1], dp2[i-2]+ money[i]);
        }
        else{
            dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
        }
    }
    answer = max(dp[money.size()-1], dp2[money.size()-1]);
    return answer;
}
