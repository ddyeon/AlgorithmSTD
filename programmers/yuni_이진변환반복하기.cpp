#include <string>
#include <vector>
#include<algorithm>
using namespace std;
string binary(int n) {
    string r = "";
    while (n != 0) {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}
vector<int> solution(string s) {
    vector<int> answer;
    string tmp;
    int zerocnt = 0;
    int changecnt = 0;
    while (s.size() != 1) {
        tmp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') tmp += "1";
            else zerocnt++;
        }
        s = binary(tmp.size());
        reverse(s.begin(), s.end());
        changecnt++;
    }    
    
    answer.push_back(changecnt);
    answer.push_back(zerocnt);

    return answer;
}
int main(void) {
    solution("110010101001");
    solution("01110");
    solution("1111111");
}