#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;

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
        if ((mid == v.size() - 1 || v[mid + 1] > x) && v[mid] == x)
            break;
        if (v[mid] <= x)
            left = mid + 1;
        else if (v[mid] > x)
            right = mid - 1;
    }

    int end = mid;

    left = 0;
    right = N - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if ((mid == 0 || v[mid - 1] < x) && v[mid] == x)
            break;
        if (v[mid] < x)
        {
            left = mid + 1;
        }
        else if (v[mid] >= x)
        {
            right = mid - 1;
        }
    }

    int start = mid;
    if (end - start < 0)
        cout << "-1" << endl;
    else
        cout << end - start + 1 << endl;

    return 0;
}