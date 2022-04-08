#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v[i] = t;
    }

    int left = 0;
    int right = N - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (v[mid] < mid)
            left = mid + 1;
        else if (v[mid] > mid)
            right = mid - 1;
        else
            break;
    }
    if (v[mid] == mid)
        cout << mid << endl;
    else
        cout << "-1" << endl;

    return 0;
}