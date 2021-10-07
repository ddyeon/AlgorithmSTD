#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    unsigned long long end = 1000000000000000001;
    unsigned long long start = 1;
    sort(times.begin(),times.end());
    while (start<=end){
        unsigned long long check = (end + start) / 2;
        unsigned long long ppl = 0;
        for (int i = 0; i < times.size(); i++){
            ppl += check / times[i];
        }
        if (ppl < n){
            start = check + 1;
        }
        else {
            if(check <= end) {
                answer = check;
            }
            end = check - 1;
        }
    }
    return answer;
}
