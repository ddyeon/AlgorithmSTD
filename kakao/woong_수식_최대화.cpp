#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ABS(x)      ((x)<0?(-x):(x))

using namespace std;

long long calculation(long long x, long long y, char op) 
{
    if (op == '+') {
        return x + y;
    }
    else if (op == '-') {
        return x - y;
    }
    return x * y;
}

long long solution(string expression) 
{
    long long answer = 0;
    vector<long long> terms;
    string tmp = "";
    char combination[6][3] = {{'+', '-', '*'}, 
                              {'+', '*', '-'}, 
                              {'-', '+', '*'}, 
                              {'-', '*', '+'}, 
                              {'*', '+', '-'}, 
                              {'*', '-', '+'}};

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            terms.push_back(atoi(tmp.c_str()));
            terms.push_back(expression[i] - 100);
            tmp = "";
        }
        else {
            tmp += expression[i];
        }
    }
    terms.push_back(atoi(tmp.c_str()));

    for (int i = 0; i < 6; i++) {
        vector<long long> tmp = terms;
        for (int j = 0; j < 3; j++) {
            int loop = tmp.size();
            for (int k = 0; k < loop; k++) {
                if (tmp.front() + 100 == combination[i][j]) {
                    tmp.erase(tmp.begin());
                    long long y = tmp.front();
                    tmp.erase(tmp.begin());
                    long long x = tmp.back();
                    tmp.pop_back();
                    tmp.push_back(calculation(x, y, combination[i][j]));
                    k += 1;
                }
                else {
                    tmp.push_back(tmp.front());
                    tmp.erase(tmp.begin());
                }
            }
        }
        answer = max(answer, ABS(tmp.front()));
    }
    return answer;
}

int main(void)
{
    cout << solution("1-1+1*1-1+1") << endl;

    return 0;
}