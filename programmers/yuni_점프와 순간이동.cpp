#include <iostream>
using namespace std;
// kĭ ������, (������� �� �Ÿ�) * 2
// ������ �Ҹ� k��ŭ, �Ҹ� x
// N��ŭ �Ÿ��� ������ ������ �̵� 

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