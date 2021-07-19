#include <string>
using namespace std;

// U: 위쪽으로 한 칸 가기
// D: 아래쪽으로 한 칸 가기
// R: 오른쪽으로 한 칸 가기
// L: 왼쪽으로 한 칸 가기

bool check[15][15][15][15];

int solution(string dirs)
{
    int answer = 0;
    int x = 5; 
    int y = 5; //음수제거

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

        //최대최소
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10)
            continue;
        if(!check[x][y][nx][ny])
        {
            check[x][y][nx][ny] = true;
            check[nx][ny][x][y] = true; //반대도 같은 경우 취급
            answer +=1;
        }

        x = nx;
        y = ny;
        
    }



    return answer;
}