#include <iostream>
using namespace std;

//아이언슈트는 건전지로 작동
//순간이동은 건전지 사용량 안줄지만 k칸 점프하면 k만큼 건전지 사용량 듬.
//점프하느냐, x2하느냐(순간이동은 건전지 안줄음)

int solution(int n)
{
    int ans = 0;

    while (n > 0)
    {
        if (n % 2 == 1) //나머지가 1되면 점프해야함.
            ans++;
        n /= 2;
    }

    return ans;
}