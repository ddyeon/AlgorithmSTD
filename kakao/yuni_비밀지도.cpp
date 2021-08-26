#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 처음 주어질땐 10진수 --> 2진수로 변환해야 함
*/

long long tenConvertTwo(int num) {
    long long result = 0;
    for (int i = 1;num > 0; i *= 10) {
        int binary = num % 2;
        result += binary * i;
        num /= 2;
    }
    return result;
}

vector<string> map1, map2;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        string one = to_string(tenConvertTwo(arr1[i]));
        if (one.size() < n) {
            while (one.size() != n) one.insert(0,"0");
        }
        string two = to_string(tenConvertTwo(arr2[i]));
        if (two.size() < n) {
            while (two.size() != n) two.insert(0, "0");
        }
        map1.push_back(one);
        map2.push_back(two);
    }
    for (int i = 0; i < n; i++) {
        string h = "";
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == '1' || map2[i][j] == '1' )h += "#";
            else h += " ";
        }
        answer.push_back(h);
    }

    return answer;
}

int main(void) {
    solution(16, { , 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}