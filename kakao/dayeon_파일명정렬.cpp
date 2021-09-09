#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//숫자가 숫자순으로 
//head와 number같으면 원래 순서 유지
//참고
bool cmp(pair<string, pair<string, int>> a, pair<string, pair<string, int>> b)
{
    if (a.first == b.first)
    {
        if (a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return stoi(a.second.first) < stoi(b.second.first);
    }
    else
        return a.first < b.first;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    bool hc = false, nc = false;
    vector<pair<string, pair<string, int>>> v;

    // //소문자로 전부변환
    // for(int i = 0; i < files.size(); i++)
    // {
    //     transform(files[i].begin(), files[i].end(), files[i].begin(), ::tolower);
    // }

    //head랑 name 분리하기
    string head = "";
    string number = "";
    for(int i = 0; i < files.size(); i++)
    {
        pair<string, int> p;
        for(int  j = 0; j < files[i].size(); j++)
        {
            if(hc == false) //아직 Head 탐색중
            {
                if (files[i][j] >= '0' && files[i][j] <= '9')
                {
                    hc = true;
                    number += files[i][j];
                }
                else
                    head += tolower(files[i][j]);
            }
            else if(hc && nc == false)
            {
                if(files[i][j] >= '0' && files[i][j] <= '9')
                    number += files[i][j];
                else 
                    break;
            }
                  
        }
        p = make_pair(number, i);
        v.push_back(make_pair(head, p));
        head = number = "";
        hc = nc = false;
    }
    
    stable_sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++)
    {
        answer.push_back(files[v[i].second.second]);
    }


    return answer;
}


int main()
{
// 입력: [ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" ] 
// 출력 : [ "img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png" ]


}