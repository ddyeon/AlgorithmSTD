#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
악보에 사용되는 음 C, C#, D, D#, E, F, F#, G, G#, A, A#, B --12개
음은 1분에 1개씩 음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼 재생된다.
m --기억한 멜로디를 담은 문자열, musicInfo -- 방송된 곡들
음악이 시작한 시간, 끝난 시간, 음악 제목, 악보 정보
*/
struct Node {
    int index;
    string title;
};
struct Node2 {
    int index;
    string title, music;
};
unordered_map<string, Node> uno; // 음정, 제목
vector<Node2> node;
bool oper(Node2 n1, Node2 n2) {
    if (n1.music.size() < n2.music.size())return false;
    else if (n1.music.size() == n2.music.size()) {
        if(n1.index < n2.index) return true;

    }
    else return true;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string title = "";
    string music = "";
    for (int i = 0; i < musicinfos.size(); i++) {
        int startTime = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
        int endTime = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));
        int duringTime = endTime - startTime;
        title = "";
        music = "";
        int j = 12;
        for (j = 12; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j] == ',')break;
            title += musicinfos[i][j];
        }
        int size = 0;
        for (j = j + 1; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j] != '#')size++;
            music += musicinfos[i][j];
        }
        if (size > duringTime) {
            for (int k = size; k > duringTime; k--) {
                if (music[music.size() - 1] == '#') music.erase(music.size() - 2);
                music.erase(music.size() - 1);

            }
        }
        else if (size < duringTime) {
            while (size < duringTime) {
                music += music;
                size *= 2; 
            }
            if (size > duringTime) {
                for (int k = size; k > duringTime; k--) {
                    if (music[music.size()-1] == '#') music.erase(music.size() - 2);
                    music.erase(music.size() - 1);

                }
            }
        }
        uno[music] = { i, title };
    }
    for (auto a = uno.begin(); a != uno.end(); ++a) {
        string isit = a->first;
        int f = isit.find(m);
        if (f != -1 && isit[f + m.size()] != '#') {
            node.push_back({ a->second.index, a->second.title, isit });
        }
    }
    sort(node.begin(), node.end(), oper);
    if (node.size() == 0) answer = "(None)";
    else answer = node[0].title;
    return answer;
}
int main(void) {
    solution("ABC", { "12:00,12:4,HELLO,C#D#E#F#GABF#B", "13:00,13:05,WORLD,ABCDEF" });
}