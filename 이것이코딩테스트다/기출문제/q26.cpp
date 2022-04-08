#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        pq.push(n);
    }

    int total = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        total += a + b;
        pq.push(a + b);
    }
    cout << total << endl;
    return 0;
}