#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<string, string>, bool>> graph; //(ICN, HND), true or false

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer;

    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++) {
        graph.push_back(make_pair(make_pair(tickets[i][0], tickets[i][1]), false));
    }

    return answer;
}

int main(void)
{

    return 0;
}