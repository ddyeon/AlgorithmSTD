#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string changeNum(int n, int num) {
    string tmp;
    
    if (num == 0)
        return to_string(0);
    
    while (num > 0) {
        if (num % n == 10)
            tmp += 'A';
        
        else if (num % n == 11)
            tmp += 'B';
        
        else if (num % n == 12)
            tmp += 'C';
        
        else if (num % n == 13)
            tmp += 'D';
        
        else if (num % n == 14)
            tmp += 'E';
        
        else if (num % n == 15)
            tmp += 'F';
        
        else
            tmp += to_string(num % n);

        num = num / n;
    }
    
    reverse(tmp.begin(), tmp.end());
    
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";

    int num = 0;
    while(str.size() <= t * m) {
        str += changeNum(n, num);
        num++;
    }
    
    int order = 0;
    while (answer.size() < t) {
        int idx = order * m + (p - 1);
        answer += str[idx];
        order++;
    }

    return answer;
}
