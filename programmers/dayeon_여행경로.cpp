#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//가능한 경로가 2개면 알파벳순으로 앞서는 경로 출력


bool visit[10001];
vector <string> result;

bool dfs(string cur, vector<vector<string>> tickets, int cnt)
{
    if(cnt == tickets.size())
        return true;

    for(int i = 0; i < tickets.size(); i++)
    {
        if(!visit[i] && cur == tickets[i][0]) //0이 목적지와 같을때까지 돌기
        {
            visit[i] = true;
            result.push_back(tickets[i][1]);
            if(dfs(tickets[i][1], tickets, cnt+1))
                return true;
            visit[i] = false; //연결된게 없으면 다시 초기화
    
        }
    }
    result.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    string start = "ICN";
    sort(tickets.begin(), tickets.end());

    result.push_back(start);
    dfs(start, tickets, 0);

    answer = result;
    
    return answer;
}

int main()
{
    // [ [ "ICN", "JFK" ], [ "HND", "IAD" ], [ "JFK", "HND" ] ] => ["ICN", "JFK", "HND", "IAD"]
    // [[ "ICN", "SFO" ], [ "ICN", "ATL" ], [ "SFO", "ATL" ], [ "ATL", "ICN" ], [ "ATL", "SFO" ]]
    // ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]



}