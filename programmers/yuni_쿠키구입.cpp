#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, int> uno;
int solution(vector<int> cookie) {
    int answer = 0;

    if (cookie.size() == 1)return 0;

    //기준 점을 생각하자
    for (int i = 0; i < cookie.size() - 1; i++) {
        int firstIdx = i;
        int secndIdx = i + 1;
        int firstSum = cookie[firstIdx];
        int secndSum = cookie[secndIdx];

        while (1) {
            if (firstSum == secndSum) {
                answer = max(firstSum, answer);
            }
            else if (secndIdx < cookie.size() - 1 && firstSum > secndSum ) {
                secndIdx++;
                secndSum += cookie[secndIdx];
            }
            else if (firstIdx > 0 && secndSum >= firstSum ) {
                firstIdx--;
                firstSum += cookie[firstIdx];
            }
            else break;
        }

    }
    return answer;
}
int main(void) {
    solution({ 1,1,2,3 });
}