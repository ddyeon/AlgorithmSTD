#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> cut1;
    vector<string> cut2;
    map<string, pair<int, int>> memo;
    double numerator = 0, denumerator = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    // 두 글자씩 끊기
    for (int i = 0; i < str1.size() - 1; i++) {
        if (!(str1[i] >= 'A' && str1[i] <= 'Z') || !(str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')) {
            continue;
        }
        cut1.push_back(str1.substr(i, 2));
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (!(str2[i] >= 'A' && str2[i] <= 'Z') || !(str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')) {
            continue;
        }
        cut2.push_back(str2.substr(i, 2));
    }

    // 다중집합
    for (auto i : cut1) {
        if (memo.find(i) != memo.end()) {
            memo[i].first++;
        }
        else {
            memo.insert({i, make_pair(1, 0)});
        }
    }
    for (auto i : cut2) {
        if (memo.find(i) != memo.end()) {
            memo[i].second++;
        }
        else {
            memo.insert({i, make_pair(0, 1)});
        }
    }

    // 교집합, 합집합 구하기
    for (auto i : memo) {
        numerator += min(i.second.first, i.second.second);
        denumerator += max(i.second.first, i.second.second);
    }

    if (denumerator == 0) {
        if (numerator == 0) {
            return 65536;
        }
        return 0;
    }

    answer = floor((double)65536 * numerator / denumerator);

    return answer;
}

int main(void)
{
    string str1 = "aa1+aa2";
    string str2 = "AAAA12";

    cout << solution(str1, str2) << endl;;

    return 0;
}