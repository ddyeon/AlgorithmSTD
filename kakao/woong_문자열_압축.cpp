#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = s.length();

    if (s.length() == 1)
        return 1;

    for (int i = 1; i <= s.length() / 2; i++) { 
        int count = 1;
        string target = s.substr(0, i);
        string tmp;
        string result;

        for (int j = i; j < s.length(); j += i) { 
            tmp = s.substr(j, i);

            if (target == tmp) 
                count++;
            else {
                if(count == 1) {
                    result += target;
                    target = tmp;
                }
                else {
                    result = result + to_string(count) + target;
                    target = tmp;
                    count = 1;
                }
            }
            
            if (j + i >= s.length()) { 
                if (count != 1) {
                    result = result + to_string(count) + target;
                    break;
                }
                else {
                    result = result + s.substr(j);
                    break;
                }
            }
        }

        if (answer > result.length()) {
            answer = result.length();
        }
    }
    
    return answer;
}

int main(void)
{
    // string s = "aabbaccc";
    // string s = "ababcdcdababcdcd";
    // string s = "abcabcdede";
    // string s = "abcabcabcabcdededededede";
    string s = "xababcdcdababcdcd";

    cout << solution(s) << endl;

    return 0;
}