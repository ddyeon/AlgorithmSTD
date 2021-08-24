#include <string>
#include <vector>
#include <iostream>
using namespace std;

string toBinary(int n, int num) {
    string Binary;

    while (num > 0) {
        if (num % 2 == 1)
            Binary += '#';
        else
            Binary += '0';
        num = num / 2;
    }
    while(Binary.size() < n)
        Binary += '0';
    reverse(Binary.begin(), Binary.end());
    return Binary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        string tmp1 = toBinary(n, arr1[i]);
        string tmp2 = toBinary(n, arr2[i]);
        string str;
        for (int i = 0; i < n; i++) {
            if (tmp1[i] == '#' || tmp2[i] == '#')
                str += '#';
            else
                str += ' ';
        }
        answer.push_back(str);
        cout << str << endl;
    }
    return answer;
}

