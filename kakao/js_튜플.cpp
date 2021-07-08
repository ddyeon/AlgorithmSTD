#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int arr[100001] = { 0 };
void solution(string s) {
    vector<int> answer;
    vector<int>vec;
    string tmp="";
    
    for (int i = 1; i < s.size() - 1; i++) {
        
        if (s[i] == '{' || s[i]==',')
            continue;
        else if (s[i] == '}') {
            int num = stoi(tmp);
            vec.push_back(num);
            tmp = "";
        }
        else
            tmp += s[i];
        
    }
    sort(vec.begin(), vec.end());
 
    for (int i = 0; i < vec.size(); i++) {
        
        for (int j = 5; j >= 0; j--) {
            int num = vec[i] / pow(10, j);
            if (num != 0) {
                if (arr[num] == 0) {
                    arr[num] = 1;
                    answer.push_back(num);
                    break;
                }
                else {
                    vec[i] -= num * pow(10, j);
                }
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;
}
int main() {
    string str = "{{20,111},{111}}";
    solution(str);
}