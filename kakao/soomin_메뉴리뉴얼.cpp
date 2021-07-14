#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
vector<string> orders;
vector<int> course;
vector<string> answer;
map <string, int> m;

bool compare(pair<string, int> a, pair < string, int> b) {
	return a.second > b.second;
}
//DFS로 모든 조합 찾아서 map에 조합별로 개수 넣기
void dfs(string order, string s, int idx, int count) {
	if (count == s.length()) {
		m[s] += 1;
		return;
	}
	for (int i = idx; i < order.length();i++) {
		s[count] = order[i];
		dfs(order, s, i + 1, count + 1);
	}

}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector <pair<string, int>> sorted; 
	for (int i = 0; i < orders.size();i++) {
		sort(orders[i].begin(), orders[i].end());
		for (int j = 0; j < course.size();j++) {
			string s = "";
			s.resize(course[j]); //참고
			dfs(orders[i], s, 0, 0);
		}

	}
	//많이 시킨 조합의 VALUE 기준으로 정렬
	for (auto& order : m) {
		if (order.second <= 1) { //2명 미만 시킨 조합 패스
			continue;
		}
		sorted.push_back(make_pair(order.first, order.second));
	}
	sort(sorted.begin(), sorted.end(), compare);

	//각 코스별로 최대값 넣기
	for (int i = 0; i < course.size();i++) {
		int max = 0;
		for (int j = 0; j < sorted.size();j++) {
			if (sorted[j].first.length() != course[i]) {
				continue;
			}
			else if (max == 0) { //처음 최대값
				answer.push_back(sorted[j].first);
				max = sorted[j].second;
			}
			else if (max == sorted[j].second) { //최대값 여러개일때
				answer.push_back(sorted[j].first);
			}
			else {
				break;
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
int main()
{
	orders.push_back("ABCFG");
	orders.push_back("AC");
	orders.push_back("CDE");
	orders.push_back("ACDE");
	orders.push_back("BCFG");
	orders.push_back("ACDEH");
	course.push_back(2);
	course.push_back(3);
	course.push_back(4);

	solution(orders, course);
	cout << "Hello World!\n";
}

