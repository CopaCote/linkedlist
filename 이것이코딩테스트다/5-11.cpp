#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {-1, 1, 0, 0}; // 상하좌우
int dy[4] = {0, 0, -1, 1};

int main()
{
    int N, M;
    vector<vector<int>> arr;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
            v.push_back(s[j] - '0');
        arr.push_back(v);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 0)
                continue;

            if (arr[nx][ny] == 1)
            {
                arr[nx][ny] = arr[p.first][p.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << "Ans : " << arr[N - 1][M - 1] << endl;

    return 0;
}