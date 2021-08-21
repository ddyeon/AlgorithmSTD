#include <string>
#include<unordered_map> 
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;
/*
자카드 유사도 집합 간의 유사도를 검사하는 여러 방법 중 하나로 
A,B 사이의 자카드 유사도 - 교집합 크기 / 합집합 크기
둘 다 공집합일 경우는 J(A, B) = 1
*/
unordered_map<string, int> jaca1;
int solution(string str1, string str2) {
    int answer = 0;
    if (str1 == "" && str2 == "") return 1;
    double geoziphap = 0;
    int str1size = 0, str2size = 0;
    if (str1[0] > 90)str1[0] -= 32;

    for (int i = 1; i < str1.size(); i++) {
        if (str1[i] > 90)str1[i] -= 32;
        if (str1[i] < 65 || str1[i]>90) {
            continue;
        }
        else {
            if (str1[i - 1] < 65 || str1[i - 1]>90) continue;
            string tmp = str1.substr(i-1, 2);
            jaca1[tmp]++;
            str1size++;
        }
    }
    if (str2[0] > 90)str2[0] -= 32;
    if (str2[0] < 65 && str2[0]>90) {
        str2.erase(0, 1);
    }
    for (int i = 1; i < str2.size(); i++) {
        if (str2[i] > 90)str2[i] -= 32;
        if (str2[i] < 65 || str2[i]>90) {
            continue;
        }
        else {
            if (str2[i - 1] < 65 || str2[i - 1] > 90) continue;
            string tmp = str2.substr(i-1, 2);
            str2size++;
            if (jaca1[tmp] > 0) {
                geoziphap++;
                jaca1[tmp]--;
            }
        }
    }
    double hapziphap = (str1size + str2size - geoziphap);
    double t = 0.0;
    if (geoziphap == 0 && hapziphap == 0)return 65536;
    t = geoziphap / hapziphap;
    t *= 65536;
    answer = floor(t);
    return answer;
}
int main(void) {
//    solution("aa1+aa2", "AAAA12");
//    solution("hanshake", "shake hands");
    solution("E=M*C^2", "e=m*c^2");
}