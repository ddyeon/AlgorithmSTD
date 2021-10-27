#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 1000;
    for (int i = 1; i <= s.size() / 2 + 1; i++) {
        int idx = 0, num = 0;
        string str="";
        string tmpstr="";
        while (idx < s.size()) {
            if (tmpstr == s.substr(idx, i))
                num++;
            else {
                if (num > 0) {
                    str += to_string(num + 1);
                    str += tmpstr;
                }
                else {
                    str += tmpstr;
                }
                num = 0;
                tmpstr = s.substr(idx, i);
            }
            idx += i;
        }
        if (num > 0) {
            str += to_string(num + 1);
            str += tmpstr;
        }
        else {
            str += tmpstr;
        }
        int len = str.size();
        cout << i << "   " << len << "   "<<str<<endl;
        answer = min(answer, len);
    }
    return answer;
}

int main() {
    string s = "a";
    cout<<solution(s);

}