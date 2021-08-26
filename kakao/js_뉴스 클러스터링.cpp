#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string lower(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }

    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = lower(str1);
    str2 = lower(str2);

    unordered_map<string, int>str1Map;
    for (int i = 0; i < str1.size() - 1; i++) {
        if (str1[i] >= 65 && str1[i] <= 90 && str1[i + 1] >= 65 && str1[i + 1] <= 90) {
            string tmp = str1.substr(i, 2);
            if (str1Map.end() == str1Map.find(tmp))
                str1Map.insert(make_pair(tmp, 1));
            else
                str1Map[tmp]++;
        }
    }

    unordered_map<string, int>str2Map;
    for (int i = 0; i < str2.size() - 1; i++) {
        if (str2[i] >= 65 && str2[i] <= 90 && str2[i + 1] >= 65 && str2[i + 1] <= 90) {
            string tmp = str2.substr(i, 2);
            if (str2Map.end() == str2Map.find(tmp))
                str2Map.insert(make_pair(tmp, 1));
            else 
                str2Map[tmp]++;
        }
    }

    int sameElement = 0, wholeElement = 0; // wholeElement은 합집합, sameElement는 교집합 원소 수

    if (str1Map.size() == 0 && str2Map.size() == 0)
        return 65536;

    for (auto& i : str1Map) {
        string tmp = i.first;
        if (str2Map.end() == str2Map.find(tmp))
            wholeElement += i.second;
        else {
            sameElement += min(str2Map[tmp], i.second);
            wholeElement += max(str2Map[tmp], i.second);
            str2Map[tmp] = 0;
        }
    }
  
    for (auto& i : str2Map)
        wholeElement += i.second;

    answer = floor((float)sameElement / (float)wholeElement * 65536);

    return answer;
}

