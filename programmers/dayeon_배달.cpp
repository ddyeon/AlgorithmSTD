#include <iostream>
#include <vector>
using namespace std;

//�÷��̵�ͼ�
int visit[51][51];

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 1; //1�ιٲ������

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
            visit[i][j] = 100001; //�ִ밪 �ʱ�ȭ
    }

    for(int i = 0; i < road.size(); i++)
    {
        int x = road[i][0]; //�����
        int y = road[i][1]; //������
        int z = road[i][2]; //����ġ

        if(visit[x][y] >= z)
        {
            visit[x][y] = z;
            visit[y][x] = z;
        }
    }

    for(int k=1; k<=N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (k == i || k == j || i == j)
                    continue;                                              //����1�϶�
                visit[i][j] = min(visit[i][j], visit[i][k] + visit[k][j]); //��ó�� ���°Ŷ� �׳ɰ��°Ŷ� ��
            }
        }
           
    }
        
    
    for(int i =2; i<=N;i++)
    {
        if(visit[1][i] <= K)
            answer++;
    }


    return answer;
}

//[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]