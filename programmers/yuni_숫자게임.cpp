#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(B.begin(), B.end());
    sort(A.begin(), A.end());

    int aidx = 0, bidx = 0;
    int size = B.size();

    while (1) {
        if (aidx >= B.size() || bidx >= B.size()) break;
        if (B[bidx] > A[aidx]) {
            answer++;
            aidx++;
            bidx++;
        }
        else bidx++;
    }

    return answer;
}