#include <iostream>
#include <string>
#include <vector>

using namespace std;

string result = "";

void trans_base(int n, int x)
{
    if (n == 0) {
        return;
    }

    trans_base(n / x, x);

    if (n % x >= 10) {
        result += to_string((char)('A' + n % x - 10));
    }
    else {
        result += to_string((char)(n % x));
    }
}


string solution(int n, int t, int m, int p)
{
    string answer = "";



    return answer;
}

int main(void)
{
    trans_base(12, 13);

    cout << result << endl;

    return 0;
}