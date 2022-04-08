#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp(pair<double, int> &a, pair<double, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second; // Stage 오름차순
    return b.first < a.first;       // 실패율 내림차순
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<int> lastStage(N + 2, 0);
    vector<pair<double, int>> percent;
    for (auto n : stages)
        lastStage[n]++;

    int totalUser = 0;

    totalUser += lastStage[N + 1];
    for (int i = N; i > 0; i--)
    {
        totalUser += lastStage[i];
        if (totalUser == 0)
            percent.push_back(make_pair(0, i));
        else
            percent.push_back(make_pair((double)lastStage[i] / totalUser, i));
    }

    sort(percent.begin(), percent.end(), comp);
    for (auto n : percent)
        answer.push_back(n.second);

    return answer;
}

int main()
{
}