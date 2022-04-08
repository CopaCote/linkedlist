// 절반은 답지 보고 풀어서 다시 풀면 제대로 해봐야할듯.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v[i] = t;
    }
    sort(v.begin(), v.end());

    int left = 1;
    int right = v[v.size() - 1] - v[0];
    int ans;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        vector<int> wifi;
        wifi.push_back(0);
        for (int i = 1; i < v.size(); i++)
            if (v[i] - v[*(wifi.end() - 1)] >= mid)
                wifi.push_back(i);
        if (wifi.size() >= C)
        { // 가능하니까 더 거리 늘리기
            left = mid + 1;
            ans = mid; // 가능할때마다 최대치 기록
        }
        else
            right = mid - 1;
    }

    cout << ans << endl;
    return 0;
}