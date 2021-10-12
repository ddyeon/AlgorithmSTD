#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_he = 0;
    int max_wi = 0;
    
   for (int i = 0;i<sizes.size();i++)
	{
		sort(sizes[i].begin(), sizes[i].end());
	}
	for (int i = 0; i < sizes.size(); i++)
	{
		max_wi = max(max_wi, sizes[i][0]);
		max_he = max(max_he, sizes[i][1]);
	}
    answer = max_wi * max_he;
    
    return answer;
}