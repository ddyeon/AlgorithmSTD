#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo[100000] {};

int solution(vector<int> sticker)
{
    int answer = 0;

    if (sticker.size() == 1) {
        return sticker[0];
    }

    //첫번째 스티커부터 선택
    memo[0] = sticker[0];
    memo[1] = sticker[0];

    for (int i = 2; i < sticker.size() - 1; i++) {
        memo[i] = max(memo[i - 2] + sticker[i], memo[i - 1]);
    }
    answer = max(answer, memo[sticker.size() - 2]);

    //두번째 스티커부터 선택
    memo[0] = 0;
    memo[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++) {
        memo[i] = max(memo[i - 2] + sticker[i], memo[i - 1]);
    }
    answer = max(answer, memo[sticker.size() - 1]);

    return answer;
}

int main(void)
{
    vector<int> sticker = {14, 6, 5, 11, 3, 9, 2, 10};

    cout << solution(sticker) << endl;

    return 0;
}