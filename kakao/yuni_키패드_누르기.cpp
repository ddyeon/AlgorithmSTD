#include <string>
#include <math.h>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int ly = 3, lx = 0;
    int ry = 3, rx = 2;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            if (numbers[i] == 1) { ly = 0; lx = 0; }
            else if (numbers[i] == 4) { ly = 1; lx = 0; }
            else if (numbers[i] == 7) { ly = 2; lx = 0; }
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            if (numbers[i] == 3) { ry = 0; rx = 2; }
            else if (numbers[i] == 6) { ry = 1; rx = 2; }
            else if (numbers[i] == 9) { ry = 2; rx = 2; }
            answer += "R";
        }
        else if (numbers[i] == 2) {
            if (abs(ly - 0) + abs(lx - 1) < abs(ry - 0) + abs(rx - 1)) { ly = 0; lx = 1; answer += "L"; }
            else if(abs(ly - 0) + abs(lx - 1) > abs(ry - 0) + abs(rx - 1)) { ry = 0; rx = 1; answer += "R"; }
            else if (abs(ly - 0) + abs(lx - 1) == abs(ry - 0) + abs(rx - 1)) {
                if(hand=="left") { ly = 0; lx = 1; answer += "L"; }
                else { ry = 0; rx = 1;answer += "R"; }
            }
        }
        else if (numbers[i] == 5) {
            if (abs(ly - 1) + abs(lx - 1) < abs(ry - 1) + abs(rx - 1)) { ly = 1; lx = 1; answer += "L"; }
            else if (abs(ly - 1) + abs(lx - 1) > abs(ry - 1) + abs(rx - 1)) { ry = 1; rx = 1;answer += "R";   }
            else if (abs(ly - 1) + abs(lx - 1) == abs(ry - 1) + abs(rx - 1)) {
                if (hand == "left") { ly = 1; lx = 1; answer += "L"; }
                else { ry = 1; rx = 1;answer += "R"; }
            }
        }
        else if (numbers[i] == 8) {
            if (abs(ly - 2) + abs(lx - 1) < abs(ry - 2) + abs(rx - 1)) { ly = 2; lx = 1;  answer += "L"; }
            else if (abs(ly - 2) + abs(lx - 1) > abs(ry - 2) + abs(rx - 1)) { ry = 2; rx = 1;answer += "R";}
            else if (abs(ly - 2) + abs(lx - 1) == abs(ry - 2) + abs(rx - 1)) {
                if (hand == "left") { ly = 2; lx = 1; answer += "L"; }
                else { ry = 2; rx = 1;answer += "R";}
            }
        }
        else if (numbers[i] == 0) {
            if (abs(ly - 3) + abs(lx - 1) < abs(ry - 3) + abs(rx - 1)) { ly = 3; lx = 1; answer += "L"; }
            else if (abs(ly - 3) + abs(lx - 1) > abs(ry - 3) + abs(rx - 1)) { ry = 3; rx = 1;answer += "R"; }
            else if (abs(ly - 3) + abs(lx - 1) == abs(ry - 3) + abs(rx - 1)) {
                if (hand == "left") { ly = 3; lx = 1;  answer += "L"; }
                else { ry = 3; rx = 1;answer += "R"; }
            }
        }
    }
    return answer;
}
int main(void) {
    solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
    solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");
    solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right");

}