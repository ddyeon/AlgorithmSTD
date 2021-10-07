#include <string>
#include <vector>

using namespace std;
//A������ B������ �׻��̱�
//��Ȯ�ϰ� ������ �ű� �� �ִ� ������ �� 
//������ �ƴ� ��� = �� �տ� �ִ� ����� �� �ڿ� ����ִ��� �˾ƾ���
//�÷��̵� �ͼ�
bool arr[101][101];

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    int visit[n+1];
    vector<int> v[n+1];
    
    for(int i = 0; i < results.size(); i++)
    {
        arr[results[i][0]][results[i][1]] = true;
    }

   for(int k =1; k <=n; k++)
    for(int i = 1; i <= n; i++)
       {
           for(int j = 0; j <= n; j++)
           {
               if(arr[i][k] && arr[k][j])
                    arr[i][j] = true; // i�� j�� ����� �� �� ����.
           }
       }

    for(int i = 1; i <=n; i++)
    {
        int front = 0;
        int end = 0;

        for(int j = 1; j<=n; j++)
        {
            if(arr[i][j]) front++;
            if(arr[j][i]) end++;
        }

        if(front + end  == n-1)
            answer++;
    }

    return answer;
}

int main()
{
    //[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]
}