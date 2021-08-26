#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 비밀지도 김수민
string binary(int n){
   if (n <= 3){
       return to_string(n / 2) + to_string(n % 2);
   }
    return binary(n/2) + to_string(n % 2);
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<char>> v;
    vector<vector<char>> v2;
    for (int i = 0; i < n ; i++){
        string s = "";
        string s2 = "";
        vector <char> temp;
        vector <char> temp2;
        s += binary(arr1[i]);
        s2 += binary(arr2[i]);
        if (s.size() < n){
            for (int j = 0 ; j < n - s.size(); j++){
                temp.push_back('0');
            }
            for (int j = 0; j< s.size(); j++){
                temp.push_back(s[j]);
            }
        }
        
        else{
            for (int j = 0; j < n ; j++){
                temp.push_back(s[j]);
            }
        }
        if (s2.size() < n){
            for (int j = 0 ; j < n - s2.size(); j++){
                temp2.push_back('0');
            }
            for (int j = 0; j< s2.size(); j++){
                temp2.push_back(s2[j]);
            }
        }
        else{
            for (int j = 0; j < n ; j++){
                temp2.push_back(s2[j]);
            }
        }
        v.push_back(temp);
        v2.push_back(temp2);
    }
    for (int i = 0 ; i < n ; i++){
        string secret = "";
        for(int j = 0; j < n; j++){
            if ((v[i][j] == '0') && (v2[i][j] == '0')){
                secret += ' ';
            }
            else{
                secret += '#';
            }
        }
        answer.push_back(secret);
    }
    
    return answer;
}
