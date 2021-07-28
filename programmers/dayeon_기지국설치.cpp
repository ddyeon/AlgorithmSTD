#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int current = 1; //������ġ
    int idx = 0;

    while (current <= n)
    { 

        if (idx < stations.size() && current >= stations[idx] - w) //�Ÿ��� �ȴٸ�
        {

            current = stations[idx] + w + 1; 
            idx++;                           
        }
        else //���������� ��
        { 

            current += 2 * w + 1;  //�ִ밪
            answer++;             
        }
    }

    return answer;
}

int main()
{
    // 11 [4, 11] 1 3 
    // 16 [9] 2 3
}