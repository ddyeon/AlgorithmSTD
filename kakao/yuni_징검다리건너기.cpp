#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int binarySerach(int n, vector<int> &stones) {
    int leftStone = 0;
    int maxNum = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - n <= 0)leftStone++;
        else {
            if (maxNum < leftStone) maxNum = leftStone;
            leftStone = 0;
        }
    }
    if (maxNum < leftStone) maxNum = leftStone;
    return maxNum;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    stones = stones;
    int maxStone = *max_element(stones.begin(), stones.end());
    int minStone = 1;
    while (maxStone!=minStone) {
        int mid = (maxStone + minStone) / 2;
        if (binarySerach(mid, stones) >= k) {
            maxStone = mid;
        }
        else {
            minStone = mid + 1;
        }
    }
    answer = maxStone;
     return answer;
}

int main(void) {
    solution({ 2,4,5,3,2,1,4,2,5,1 }, 3);
}
 