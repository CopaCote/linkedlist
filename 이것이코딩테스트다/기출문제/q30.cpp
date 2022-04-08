/*
1. 길이별로 나눈다.

접미사 와일드카드
2. 사전순으로 정렬한다

접두사 와일드카드
2. 글자를 뒤집어서 사전순으로 정렬한다.

3. 앞글자부터 이진탐색으로 범위를 좁힌다.
 -> upper_bound, lower_bound 사용 (정렬이 기본 가정이니까 정렬을 해야한다)
*/

// 예전에 스터디할때 이 문제를 친구가 트라이로 풀었었는데, 아마 한번 더풀게 되면 트라이로 시도해볼 듯 하다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<vector<string>> v(100000, vector<string>());
    vector<vector<string>> vr(100000, vector<string>());
    vector<int> answer;

    for (auto s : words)
    {
        v[s.size()].push_back(s);
        reverse(s.begin(), s.end());
        vr[s.size()].push_back(s);
    }

    for (int i = 0; i < v.size(); i++)
    {
        sort(v[i].begin(), v[i].end());
        sort(vr[i].begin(), vr[i].end());
    }

    for (auto q : queries)
    {
        if (q[0] == '?')
        { // 접두사
            reverse(q.begin(), q.end());
            string a = "";
            string z = "";

            int i = 0;
            while (q[i] != '?')
            {
                a += q[i];
                z += q[i];
                i++;
            }
            while (i < q.size())
            {
                a += 'a';
                z += 'z';
                i++;
            }
            int ans = upper_bound(vr[q.size()].begin(), vr[q.size()].end(), z) - lower_bound(vr[q.size()].begin(), vr[q.size()].end(), a);
            answer.push_back(ans);
        }
        else
        { // 접미사
            string a = "";
            string z = "";

            int i = 0;
            while (q[i] != '?')
            {
                a += q[i];
                z += q[i];
                i++;
            }
            while (i < q.size())
            {
                a += 'a';
                z += 'z';
                i++;
            }

            int ans = upper_bound(v[q.size()].begin(), v[q.size()].end(), z) - lower_bound(v[q.size()].begin(), v[q.size()].end(), a);
            answer.push_back(ans);
        }
    }

    return answer;
}