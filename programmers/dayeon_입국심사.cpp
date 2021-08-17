#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//n보다 작아지는 경우를 찾는다.

long long solution(int n, vector<int> times)
{
    long long answer = 0;

    long long left = 1;
    long long maxV = *max_element(times.begin(), times.end());
    long long right = maxV * n;

    while(left <= right)
    {
        long long mid = (left +right) /2;
        long long people = 0;

        for(int i = 0; i < times.size(); i++)
        {
            people += mid / times[i]; //해당하는  사람 수 저장
        }

        if (people < n)
            left = mid + 1;
        else
        {
            if(mid <= right)
                answer = mid;
            
            right = mid -1;
        }
        
    }



    return answer;
}

int main()
{
    //6, [7,10], 28

     
}