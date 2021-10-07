#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string cal(int cur, int n)
{
    string tmp = "";
    while(cur/n !=0)
    {
        int num = cur % n;
        tmp += to_string(num);
        cur /= n;
    }
    if(cur == 1)
        tmp += to_string(1);
    else
        tmp += to_string(cur/n);

    reverse(tmp.begin(), tmp.end());

    return tmp;
    
}

char alpha(int cur)
{
    if(cur == 10) return 'A';
    else if(cur == 11) return 'B';
    else if (cur == 12)
        return 'C';
    else if (cur == 13)
        return 'D';
    else if (cur == 14)
        return 'E';
    else
        return 'F';
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    string s ="";

    for(int i = 0; i < t*m; i++)
    {
        if( i <= 9)
            s += cal(i, n);
        else 
            s+= alpha(i);

    }
    int q = p-1;
    for(int i = 0 ; i < t; i++)
    {
        answer += s[q];
        q = q + m;
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    solution(16,16,2,2);
}
