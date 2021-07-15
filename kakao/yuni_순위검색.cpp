#include <string>
#include <vector>

using namespace std;
//java, cpp, python -
//frontend backend -
//junior senior -
//chicken pizza -
//Á¡¼ö    
vector<string> arr[50001];
string language, job, year, food, score;
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < info.size(); i++) {

        if (info[i][0] == 'j') { 
            arr[i].push_back("java"); 
            info[i].erase(0, 5);
        }
        else if (info[i][0] == 'c') {
            arr[i].push_back("cpp");
            info[i].erase(0, 4);
        }
        else if (info[i][0] == 'p') {
            arr[i].push_back("python");
            info[i].erase(0, 7);
        }

        if (info[i][0] == 'f') {
            arr[i].push_back("frontend");
            info[i].erase(0, 9);
        }
        else if (info[i][0] == 'b') {
            arr[i].push_back("backend");
            info[i].erase(0, 8);
        }

        if (info[i][0] == 'j') {
            arr[i].push_back("junior");
            info[i].erase(0, 7);
        }
        else if (info[i][0] == 's') {
            arr[i].push_back("senior");
            info[i].erase(0, 7);
        }

        if (info[i][0] == 'c') {
            arr[i].push_back("chicken");
            info[i].erase(0, 8);
        }
        else if (info[i][0]=='p') {
            arr[i].push_back("pizza");
            info[i].erase(0, 6);
        }

        arr[i].push_back(info[i]);
    }
    int sum = 0;
    for (int i = 0; i < query.size(); i++) {
        sum = 0;
        ////////////////////////////////////////
        if (query[i][0] == 'j') {
            query[i].erase(0, 9);
            language = "java";
        }
        else if (query[i][0] == 'c') {
            query[i].erase(0, 8);
            language = "cpp";
        }
        else if (query[i][0] == 'p') {
            query[i].erase(0, 11);
            language = "python";
        }
        else if (query[i][0] == '-') {
            query[i].erase(0, 6);
            language = "-";
        }
       
        ////////////////////////////////////////
        if (query[i][0] == 'f') {
            query[i].erase(0, 13);
            job = "frontend";
        }
        else if (query[i][0] == 'b') {
            query[i].erase(0, 12);
            job = "backend";
        }
        else if (query[i][0] == '-') {
            query[i].erase(0, 6);
            job = "-";
        }

        ////////////////////////////////////////

        if (query[i][0] == 'j') {
            query[i].erase(0, 11);
            year = "junior";
        }
        else if (query[i][0] == 's') {
            query[i].erase(0, 11);
            year = "senior";
        }
        else if (query[i][0] == '-') {
            query[i].erase(0, 6);
            year = "-";
        }
 
        ////////////////////////////////////////

        if (query[i][0] == 'c') {
            query[i].erase(0, 8);
            food = "chicken";
        }
        else if (query[i][0] == 'p') {
            query[i].erase(0, 6);
            food = "pizza";
        }
        else if (query[i][0] == '-') {
            query[i].erase(0, 2);
            food = "-";
        }
        score = query[i];
        int cnt = 0;//language, job, year, food;
        for (int i = 0; i < info.size(); i++) {
            cnt = 0;
            if (language == "-" || language == arr[i][0])cnt++;
            if (cnt == 0)continue;
            if (job == "-" || job == arr[i][1])cnt++;
            if (cnt == 1)continue;
            if (year == "-" || year == arr[i][2])cnt++;
            if (cnt == 2)continue;

            if (food == "-" || food == arr[i][3])cnt++;
            if (cnt == 3)continue;

            if (score == "-" || stoi(score) <= stoi(arr[i][4])) cnt++;

            if (cnt == 5) sum++;
        }
        answer.push_back(sum);
    }
    return answer;
}
int main(void) {
    solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" },
        { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
}