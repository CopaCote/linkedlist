#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A, B;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        A.push_back(n);
    }
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        B.push_back(n);
    }

    while (K > 0)
    {
        auto minA = min_element(A.begin(), A.end());
        auto maxB = max_element(B.begin(), B.end());
        if (*minA < *maxB)
        {
            swap(*minA, *maxB);
            K--;
        }
        else
            break;
    }

    int sum = 0;
    for (int n : A)
        sum += n;
    cout << "Ans : " << sum << endl;
    return 0;
}