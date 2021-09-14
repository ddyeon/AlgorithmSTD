#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//��������� ���� ������ ������ ���� + �ι�°�� ���� ���� ������ ������*2
int solution(vector<int> scoville, int K)
{
    int answer = 0;
   priority_queue <int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    
    while(pq.size() > 1 && pq.top() < K)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second*2);
        answer++;
    }
    
    if(pq.top() < K)
        return -1;
    else
        return answer;
}
