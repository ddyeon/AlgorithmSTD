#include <string>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
bool check(deque<char> d){
    stack <char> s;
    for (int i = 0 ; i < d.size(); i++){
        if ((d[i] == '(') or (d[i] == '{') or (d[i] == '[')){
            s.push(d[i]);
        }
        else{
            if (s.empty()) return false;
            if (d[i] == ')'){
                if (s.top() == '(') s.pop();
                else return false;
            }
            else if (d[i] == '}'){
                if (s.top() == '{') s.pop();
                else return false;
            }
            else{
                if (s.top() == '[') s.pop();
                else return false;
            }
        }
    }
    if (s.empty())return true;
    else return false;
}
int solution(string s) {
    int answer = 0;
    deque <char> d;
    for (int i = 0; i < s.size(); i++){
        d.push_back(s[i]);
    }
    for (int x = 0; x < s.size(); x++){
        if (x > 0) {
            char s = d[0];
            d.pop_front();
            d.push_back(s);
        }
        if (check(d)) answer += 1;
    }
    return answer;
}
