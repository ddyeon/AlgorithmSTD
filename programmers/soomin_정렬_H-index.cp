#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < n; i++){
            if(citations[i] > i){
                    answer++;
                }
            else{
                break;
            }
    }
    return answer;
}
