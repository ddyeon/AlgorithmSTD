#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    int arr[n+1][n+1];

    int max_num = (n*(n+1)) / 2;

    int top = 1;
    int bottom = n;
    int left = 1;
    int right = 0;

    int num = 1;
    int current = 0;

    while (num <= max_num)
    {
        if (current == 0) // 맨 바깥쪽 위에서 아래
        {
            for(int i = top; i <= bottom; i++)
            {
                arr[i][left] = num++;
            }
            top++;
            left++;
            current = 1;
        }
        else if (current == 1) //왼쪽에서 오른쪽
        {
            for(int i = left; i <= bottom-right; i++)
            {
                arr[bottom][i] = num++;
            }
            bottom--;
            current = 2;
        }
        else if (current == 2) // 아래에서 위
        {
            for(int i = bottom; i >= top; i--)
            {
                arr[i][i - right] = num++;
            }
            right++;
            top++;
            current = 0;
        }

    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= i; j++)
            answer.push_back(arr[i][j]);
    }
    
    return answer;
}