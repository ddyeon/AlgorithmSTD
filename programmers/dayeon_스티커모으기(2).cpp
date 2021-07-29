#include <iostream>
#include <vector>
using namespace std;
//ù��°�� ����� �ȶ���� ���� �ʿ�.
int dp[100001];


int solution(vector<int> sticker)
{
    int answer = 0;

    int n = sticker.size();

    if (n == 1)
        return sticker[0];

    dp[0] = sticker[0];
    dp[1] = sticker[0];


    for (int i = 2; i < n - 1; i++) //ù��° ��°��
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = max(answer, dp[n - 2]);

    dp[0] = 0;
    dp[1] = sticker[1];


    for (int i = 2; i < n; i++) //ù��° �ȶ�°��
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