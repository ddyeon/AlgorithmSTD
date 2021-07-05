#include <string>
#include <vector>

using namespace std;
vector<string> ex;
vector<string> calc(string c, vector<string> v) {
    long long answer = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == c) {
            long long left = stoll(v[i - 1]);
            long long right = stoll(v[i + 1]);
            if (c == "*")answer = left * right;
            else if (c == "-")answer = left - right;
            else if (c == "+")answer = left + right;
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            v[i - 1] = to_string(answer);
            i -= 2;
        }
    }
    return v;
}
long long solution(string expression) {
    long long answer = 0;
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if(expression[i]>='0'&& expression[i]<='9') tmp += expression[i];
        else {
            ex.push_back(tmp);
            ex.push_back(string(1,expression[i]));
            tmp = "";
        }
    }
    ex.push_back(tmp);
    ////////////////////////////////////여기까지는 vector에 집어넣은 거고
    vector<string> v = ex;
    v = calc("*", v); v = calc("+", v); v = calc("-", v);
    tmp = v.back();
    answer = max(answer, abs(stoll(tmp)));
    v = ex;
    v = calc("*", v); v = calc("-", v); v = calc("+", v);
    tmp = v.back();
    answer = max(answer, abs(stoll(tmp)));

    v = ex;
    v = calc("+", v); v = calc("-", v); v = calc("*", v);
    tmp = v.back();
    answer = max(answer, abs(stoll(tmp)));
    v = ex;
    v = calc("+", v); v = calc("*", v); v = calc("-", v);
    tmp = v.back();
    answer = max(answer, abs(stoll(tmp)));


    v = ex;
    v = calc("-", v); v = calc("*", v); v = calc("+", v);
    tmp = v.back();
    answer = max(answer, abs(stoll(tmp)));
    v = ex;
    v = calc("-", v); v = calc("+", v); v = calc("*", v);
    tmp = v.back();
    answer = max(answer, abs(stoll(tmp)));

    return answer;
}
int main(void) {
    solution("100-200*300-500+20");
    solution("50*6-3*2");
}