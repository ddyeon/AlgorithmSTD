// 위클리챌린지 5주차-모음사전 (김수민)
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
int cal(int s, int idx){
    int tmp = 0;
    for (int i = 0; i < 5 - idx; i++){
        tmp += pow(5, i);
    }
    return s * tmp;
}
int solution(string word) {
    int answer = 0;
    unordered_map <char, int> smaller;
    char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < 5; i++){
        smaller[alpha[i]] = i;
    }
    for (int i = 0; i < word.size(); i++){
        answer += cal(smaller[word[i]], i);
        if (i >= 1) answer += 1;
    }
    return answer + 1;
}
