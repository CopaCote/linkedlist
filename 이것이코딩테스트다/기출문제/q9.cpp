#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool comp(string s1, string s2)
{
    return s1.size() < s2.size();
}

int solution(string s)
{
    vector<string> result;
    // size가 1이면 아예 아래 반복문이 돌아가지 않으므로 예외처리.
    if (s.size() == 1)
        return 1;

    // 반복 단위
    for (int i = 1; i <= s.size() / 2; i++)
    {
        string s2 = "";
        int j = 0;
        // j부터 i개를 묶어서 같은 개수 찾기
        while (j < s.size())
        {
            // 나누어 떨어지지 않더라도, 뒤에 남은 부분만 짤라져서 나오기 때문에 처리가능.
            string cmp = s.substr(j, i);
            int sets = 1;
            int pos = j + i;
            // [j,j+i-1]과 [pos, pos+i-1] 비교
            while (pos + i <= s.size())
            {
                if (cmp != s.substr(pos, i))
                    break;
                pos += i;
                sets++;
            }
            if (sets > 1)
            {
                s2 += to_string(sets);
                j = pos;
            }
            else
                j += i;
            s2 += cmp;
        }
        // cout << s2 << endl;
        result.push_back(s2);
    }
    return (*min_element(result.begin(), result.end(), comp)).size();
}