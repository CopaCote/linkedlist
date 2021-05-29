#include <string>
#include <vector>

using namespace std;

void moveHanoi(int N, int start, int mid, int last, vector<vector<int>> &answer)
{
    if (N == 0)
        return;
    moveHanoi(N - 1, start, last, mid, answer);
    answer.push_back({start, last});
    moveHanoi(N - 1, mid, start, last, answer);
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    moveHanoi(n, 1, 2, 3, answer);

    return answer;
}