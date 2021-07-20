#include <string>
using namespace std;

// U: �������� �� ĭ ����
// D: �Ʒ������� �� ĭ ����
// R: ���������� �� ĭ ����
// L: �������� �� ĭ ����

bool check[15][15][15][15];

int solution(string dirs)
{
    int answer = 0;
    int x = 5; 
    int y = 5; //��������

    for(int i = 0; i < dirs.size(); i++)
    {
        int nx = x;
        int ny = y;

        if(dirs[i] == 'U')
        {
           ny -= 1;
        }
        else if(dirs[i] == 'L')
        {
            nx -= 1;
        }
        else if(dirs[i] == 'D')
        {
            ny +=1;
        }
        else if(dirs[i] == 'R') 
        {
            nx += 1;
        }

        //�ִ��ּ�
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10)
            continue;
        if(!check[x][y][nx][ny])
        {
            check[x][y][nx][ny] = true;
            check[nx][ny][x][y] = true; //�ݴ뵵 ���� ��� ���
            answer +=1;
        }

        x = nx;
        y = ny;
        
    }



    return answer;
}