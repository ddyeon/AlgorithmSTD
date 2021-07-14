#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
vector<string> info;
vector<string> query;
map <int, vector<string>> m;
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<string>check;
	for (int i = 0; i < info.size();i++) {
		istringstream ss(info[i]);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' ')) {
			m[i].push_back(stringBuffer);
		}
		
	}

	for (int i = 0; i < query.size();i++) {
		int cnt=0;
		check.clear();
		istringstream ss(query[i]);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' ')) {
			if (stringBuffer != "and") {
				check.push_back(stringBuffer);
			}	
		}
		for (auto& c : m) {
			bool flag = true;
			for (int j = 0; j < 4; j++) {
				if (check[j] == "-") {
					continue;
				}
				else if (c.second[j] != check[j]) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				int score = stoi(check[4]);
				int myscore = stoi(c.second[4]);
				if (myscore >= score) {
					cnt += 1;
				}
			}
		}
		answer.push_back(cnt);


	}
	return answer;
}

int main() {
	info.push_back("java backend junior pizza 150");
	info.push_back("python frontend senior chicken 210");
	info.push_back("python frontend senior chicken 150");
	info.push_back("cpp backend senior pizza 260");
	info.push_back("java backend junior chicken 80");
	info.push_back("python backend senior chicken 50");
	query.push_back("java and backend and junior and pizza 100");
	query.push_back("python and frontend and senior and chicken 200");
	query.push_back("cpp and - and senior and pizza 250");
	query.push_back("- and backend and senior and - 150");
	query.push_back("- and - and - and chicken 100");
	query.push_back("- and - and - and - 150");
	solution(info, query);
}
