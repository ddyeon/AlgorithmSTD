#include <string>
#include <vector>

using namespace std;
//하나라도 벽이면 벽, 둘다 공백이면 공백

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    int visit1[n][n];
    int visit2[n][n];

    string s;

    for(int i = 0; i < n; i++)
    {
        int tmp1 = arr1[i];
        int tmp2 = arr2[i];

        for(int j = n-1; j >=0; --j)
        {
            visit1[i][j] = tmp1 % 2;
            visit2[i][j] = tmp2 % 2;
            tmp1 /= 2;
            tmp2 /= 2;

        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visit1[i][j] == 0 && visit2[i][j] == 0 )
                s += ' ';
            else
                s += '#';
        }
        answer.push_back(s);
        s.clear();
    }


    return answer;
}

int main()
{
    //[9, 20, 28, 18, 11]
    //[30, 1, 21, 17, 28]
}