#include <string>
#include <vector>

using namespace std;

bool checkLock(vector<vector<int>> &key, vector<vector<int>> &lock, int key_x, int key_y, int x_min, int x_max, int y_min, int y_max)
{
    int M = key.size();
    for (int x = x_min; x <= x_max; x++)
    {
        for (int y = y_min; y <= y_max; y++)
        {
            if ((x >= key_x) && (x < key_x + M) && (y >= key_y) && (y < key_y + M) && (lock[y][x] + key[y - key_y][x - key_x] != 1))
                return false;
            else if ((x >= key_x) && (x < key_x + M) && (y >= key_y) && (y < key_y + M) && (lock[y][x] + key[y - key_y][x - key_x] == 1))
                continue;
            else if (lock[y][x] != 1)
                return false;
        }
    }
    return true;
}

void spin(vector<vector<int>> &key)
{
    vector<vector<int>> temp = key;
    int N = key.size() - 1;
    for (int y = 0; y <= N; y++)
        for (int x = 0; x <= N; x++)
            key[x][N - y] = temp[y][x];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int N = lock.size();
    int M = key.size();
    int x_min = N, x_max = -1, y_min = N, y_max = -1;

    // Minimum Square
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (lock[y][x] == 0)
            {
                x_min = min(x_min, x);
                x_max = max(x_max, x);
                y_min = min(y_min, y);
                y_max = max(y_max, y);
            }
        }
    }
    if (x_min == N || y_min == N)
        return true;
    // x_min - M + 1 ~ x_max
    // y_min - M + 1 ~ y_max
    for (int k = 0; k < 4; k++)
    {
        for (int i = x_min - M + 1; i <= x_max; i++)
        {
            for (int j = y_min - M + 1; j <= y_max; j++)
            {
                // Key의 Lock기준 좌표
                // Key의 범위 : [i,i+M-1], [j,j+M-1]
                if (checkLock(key, lock, i, j, x_min, x_max, y_min, y_max))
                    return true;
            }
        }
        if (k < 3)
            spin(key);
    }

    return false;
}