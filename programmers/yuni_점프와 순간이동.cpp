#include <iostream>
using namespace std;
// k칸 앞으로, (현재까지 온 거리) * 2
// 건전지 소모 k만큼, 소모 x
// N만큼 거리가 떨어진 곳으로 이동 

int solution(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
int main(void) {
    solution(5);
    solution(6);
    solution(5000);
}