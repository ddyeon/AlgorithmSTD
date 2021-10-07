#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 뉴스 클러스터링 김수민
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    vector<string>::iterator iter;
    for (int i = 0; i < str1.size() - 1; i++) {
        char s1 = tolower(str1[i]);
        char s2 = tolower(str1[i + 1]);
        if (!((((s1 >= 'a') and (s1 <= 'z')))) or (!((s2 >= 'a') and (s2 <= 'z')))) {
            continue;
        }
        string tmp_s1(1, s1);
        string tmp_s2(1, s2);
        string s = tmp_s1 + tmp_s2;
        v1.push_back(s);
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        char s1 = tolower(str2[i]);
        char s2 = tolower(str2[i + 1]);
        if (!((((s1 >= 'a') and (s1 <= 'z')))) or (!((s2 >= 'a') and (s2 <= 'z')))) {
            continue;
        }
        string tmp_s1(1, s1);
        string tmp_s2(1, s2);
        string s = tmp_s1 + tmp_s2;
        v2.push_back(s);
    }
    if ((v1.empty()) && (v2.empty())) {
        return 65536;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector <string> hap(v1.size() + v2.size());
    vector <string> gyo(v1.size() + v2.size());
    iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), hap.begin());
    hap.resize(iter - hap.begin());
    iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), gyo.begin());
    gyo.resize(iter - gyo.begin());
    answer = double(gyo.size()) / double(hap.size()) * 65536;
    return answer;
}
