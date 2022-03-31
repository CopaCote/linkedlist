#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, string>> v;

    for (int i = 0; i < N; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        v.push_back(make_pair(score, name));
    }

    sort(v.begin(), v.end());

    for (auto &p : v)
    {
        cout << p.second << " ";
    }
    cout << endl;

    return 0;
}