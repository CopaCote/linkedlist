#include <string>
#include <vector>

using namespace std;

bool convertable(string begin, string target)
{
    int count = 0;
    for (int i = 0; i < begin.size(); i++)
    {
        if (begin[i] != target[i])
            count++;
    }
    return count == 1;
}

int dfs(int cur, int target, vector<string> &words, vector<bool> &visited, int depth)
{
    int min_depth = 51;
    if (cur == target)
        return depth;
    visited[cur] = true;
    for (int i = 0; i < words.size(); i++)
    {
        if (!visited[i] && convertable(words[cur], words[i]))
        {
            min_depth = min(min_depth, dfs(i, target, words, visited, depth + 1));
        }
    }
    visited[cur] = false;
    return min_depth;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    int begin_i = words.size(), target_i = -1;
    vector<bool> visited(words.size() + 1);
    for (int i = 0; i < words.size(); i++)
        if (words[i] == target)
            target_i = i;

    if (target_i == -1)
        return 0;

    words.push_back(begin);

    int result = dfs(begin_i, target_i, words, visited, 0);
    if (result == 51)
        return 0;
    return result;
}