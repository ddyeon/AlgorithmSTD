#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

stack<string>visitedOrder;
bool visited[10000];
// unordered_map -> key에 출발지, value에 도착지(vector)로 받고, back으로 조회하고 popback으로 visited 표시하면 더 좋을 듯 
vector<string> solution(vector<vector<string>> tickets) {
	
	sort(tickets.begin(), tickets.end());

	vector<string> answer;
	visitedOrder.push("ICN");
	
	while (!visitedOrder.empty()) {
		string cur = visitedOrder.top();
		bool tmp = true;
		
		for (int i = 0; i < tickets.size(); i++) {
			if (tickets[i][0] == cur && visited[i] == false) {
				visited[i] = true;
				visitedOrder.push(tickets[i][1]);
				tmp = false;
				break;
			}
		}

		if (tmp) {
			answer.push_back(cur);
			visitedOrder.pop();
		}
	}
	
	reverse(answer.begin(), answer.end());

	return answer;
}
