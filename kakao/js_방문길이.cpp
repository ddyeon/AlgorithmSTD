#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[11][11][11][11] = { 0 };
int solution(string dirs) {
    int answer = 0;
    int startx = 5, starty = 5; 
    for (int i = 0; i < dirs.size(); i++) {
       
        if (dirs[i] == 'U') {
            if (starty - 1 >= 0) {
                if (arr[startx][starty][startx][starty - 1] == 0) {
                    arr[startx][starty][startx][starty - 1] = 1;
                    arr[startx][starty - 1][startx][starty] = 1;
                    answer++;
                }
                starty -= 1;
            }
        }
        else if (dirs[i] == 'D') {
            if (starty + 1 <= 10) {
                if (arr[startx][starty][startx][starty + 1] == 0) {
                    arr[startx][starty][startx][starty + 1] = 1;
                    arr[startx][starty + 1][startx][starty] = 1;
                    answer++;
                }
                starty += 1;
            }
        }
        else if (dirs[i] == 'L') {
            if (startx - 1 >= 0) {
                if (arr[startx][starty][startx - 1][starty] == 0) {
                    arr[startx][starty][startx - 1][starty] = 1;
                    arr[startx - 1][starty][startx][starty] = 1;
                    answer++;
                }
                startx -= 1;
            }
        }
        else if (dirs[i] == 'R') {
            if (startx + 1 <= 10) {
                if (arr[startx][starty][startx + 1][starty] == 0) {
                    arr[startx][starty][startx + 1][starty] = 1;
                    arr[startx + 1][starty][startx][starty] = 1;
                    answer++;
                }
                startx += 1;
            }
        }
    }
    return answer;
}
