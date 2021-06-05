#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool dfs(string cur, map<vector<string>, bool> &visited, map<string, set<string>> &m, vector<string> &result)
{
    auto it1 = visited.begin();
    while (it1 != visited.end())
    {
        if (it1->second == false)
            break;
        it1++;
    }
    if (it1 == visited.end())
    {
        result.push_back(cur);
        return true;
    }

    auto it = m.find(cur);
    for (string dest : it->second)
    {
        auto visit = visited.find({cur, dest});
        if (!(visit->second))
        {
            visit->second = true;
            if (dfs(dest, visited, m, result))
            {
                result.push_back(cur);
                return true;
            }
            visit->second = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    map<string, set<string>> m;
    map<vector<string>, bool> visited;

    for (vector<string> &v : tickets)
    {
        for (string t : v)
        {
            if (m.find(t) == m.end()) // ¾øÀ¸¸é
                m.insert(make_pair(t, set<string>()));
        }
        m.find(v[0])->second.insert(v[1]);
        visited.insert(make_pair(v, false));
    }

    vector<string> result;
    dfs(string("ICN"), visited, m, result);
    std::reverse(result.begin(), result.end());
    return result;
}